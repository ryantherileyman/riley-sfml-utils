
#include <math.h>
#include <vector>
#include <r3/string/r3-string-utils.hpp>
#include <r3/sfml/text/r3-sfml-TextUtils.hpp>
#include <r3/sfml/text/r3-sfml-MultilineTypesettingBlock.hpp>

namespace r3 {

	namespace sfml {

		const wchar_t SFML_TEXT_NEWLINE = L'\n';
		const wchar_t* SFML_TEXT_WHITESPACE_CHAR_SET = L" \t";

		MultilineTypesettingBlock::MultilineTypesettingBlock(const FontFamily& fontFamily) {
			this->fontFamily = &fontFamily;
		}

		void MultilineTypesettingBlock::updateTypesetting(const TypesettingDefn& typesettingDefn) {
			this->typesettingDefn = typesettingDefn;
		}

		unsigned int MultilineTypesettingBlock::getCharacterSize() const {
			return this->typesettingDefn.characterSize;
		}

		void MultilineTypesettingBlock::setCharacterSize(unsigned int characterSize) {
			this->typesettingDefn.characterSize = characterSize;
		}

		float MultilineTypesettingBlock::getLineSpacing() const {
			return this->typesettingDefn.lineSpacing;
		}

		void MultilineTypesettingBlock::setLineSpacing(float lineSpacing) {
			this->typesettingDefn.lineSpacing = lineSpacing;
		}

		float MultilineTypesettingBlock::getLetterSpacing() const {
			return this->typesettingDefn.letterSpacing;
		}

		void MultilineTypesettingBlock::setLetterSpacing(float letterSpacing) {
			this->typesettingDefn.letterSpacing = letterSpacing;
		}

		sf::Uint32 MultilineTypesettingBlock::getStyle() const {
			return this->typesettingDefn.style;
		}

		void MultilineTypesettingBlock::setStyle(sf::Uint32 style) {
			this->typesettingDefn.style = style;
		}

		sf::Color MultilineTypesettingBlock::getFillColor() const {
			return this->typesettingDefn.fillColor;
		}

		void MultilineTypesettingBlock::setFillColor(const sf::Color& color) {
			this->typesettingDefn.fillColor = color;
		}

		sf::Color MultilineTypesettingBlock::getOutlineColor() const {
			return this->typesettingDefn.outlineColor;
		}

		void MultilineTypesettingBlock::setOutlineColor(const sf::Color& color) {
			this->typesettingDefn.outlineColor = color;
		}

		float MultilineTypesettingBlock::getOutlineThickness() const {
			return this->typesettingDefn.outlineThickness;
		}

		void MultilineTypesettingBlock::setOutlineThickness(float outlineThickness) {
			this->typesettingDefn.outlineThickness = outlineThickness;
		}

		void MultilineTypesettingBlock::updateRegion(const TextBlockRegionDefn& regionDefn) {
			this->textBlockRegionDefn = regionDefn;
		}

		TextAlignment MultilineTypesettingBlock::getTextAlignment() const {
			return this->textBlockRegionDefn.textAlignment;
		}

		void MultilineTypesettingBlock::setTextAlignment(TextAlignment alignment) {
			this->textBlockRegionDefn.textAlignment = alignment;
		}

		VerticalAlignment MultilineTypesettingBlock::getVerticalAlignment() const {
			return this->textBlockRegionDefn.verticalAlignment;
		}

		void MultilineTypesettingBlock::setVerticalAlignment(VerticalAlignment alignment) {
			this->textBlockRegionDefn.verticalAlignment = alignment;
		}

		sf::Vector2f MultilineTypesettingBlock::getPosition() const {
			return this->textBlockRegionDefn.position;
		}

		void MultilineTypesettingBlock::setPosition(sf::Vector2f position) {
			this->textBlockRegionDefn.position = position;
		}

		sf::Vector2f MultilineTypesettingBlock::getScale() const {
			return this->textBlockRegionDefn.scale;
		}

		void MultilineTypesettingBlock::setScale(sf::Vector2f scale) {
			this->textBlockRegionDefn.scale = scale;
		}

		float MultilineTypesettingBlock::getRotation() const {
			return this->textBlockRegionDefn.rotationDegrees;
		}

		void MultilineTypesettingBlock::setRotation(float rotationDegrees) {
			this->textBlockRegionDefn.rotationDegrees = rotationDegrees;
		}

		float MultilineTypesettingBlock::getMaxLineWidth() const {
			return this->textBlockRegionDefn.maxLineWidth;
		}

		void MultilineTypesettingBlock::setMaxLineWidth(float maxLineWidth) {
			this->textBlockRegionDefn.maxLineWidth = maxLineWidth;
		}

		bool MultilineTypesettingBlock::getRoundingCorrection() const {
			return this->roundingCorrectionFlag;
		}

		void MultilineTypesettingBlock::setRoundingCorrection(bool roundingCorrection) {
			this->roundingCorrectionFlag = roundingCorrection;
		}

		std::vector<sf::Text> MultilineTypesettingBlock::createTextList(const sf::String& string) const {
			sf::Text typesettingText = this->fontFamily->createTextWithTypesetting(this->typesettingDefn);
			typesettingText.setScale(this->textBlockRegionDefn.scale);

			std::vector<std::wstring> sourceLineList = r3::StringUtils::split(string.toWideString(), SFML_TEXT_NEWLINE);

			std::vector<std::wstring> outputLineList;
			for (const auto& currSourceLine : sourceLineList) {
				typesettingText.setString(currSourceLine);

				float currLineWidth = r3::sfml::TextUtils::resolveTextWidth(typesettingText);
				if (currLineWidth <= this->textBlockRegionDefn.maxLineWidth) {
					outputLineList.push_back(currSourceLine);
				}
				else {
					size_t nextWordStartPos = 0;
					size_t currPhraseStartPos = 0;
					std::wstring currPhrase;
					std::wstring lookAheadPhrase;

					bool doneFlag = false;
					while (!doneFlag) {
						size_t nextSpacePos = r3::StringUtils::findNextPosInCharSet(currSourceLine, nextWordStartPos, SFML_TEXT_WHITESPACE_CHAR_SET);

						if (nextSpacePos == std::wstring::npos) {
							nextSpacePos = currSourceLine.size();
						}

						lookAheadPhrase = currSourceLine.substr(currPhraseStartPos, nextSpacePos - currPhraseStartPos);
						typesettingText.setString(lookAheadPhrase);
						float lookAheadTextWidth = r3::sfml::TextUtils::resolveTextWidth(typesettingText);

						if (lookAheadTextWidth > this->textBlockRegionDefn.maxLineWidth) {
							if (currPhrase.empty()) {
								nextWordStartPos = r3::StringUtils::findNextPosNotInCharSet(currSourceLine, nextSpacePos, SFML_TEXT_WHITESPACE_CHAR_SET);
							}
							else {
								outputLineList.push_back(currPhrase);

								currPhraseStartPos = nextWordStartPos;
								currPhrase.clear();
							}
						}
						else {
							currPhrase = currSourceLine.substr(currPhraseStartPos, nextSpacePos - currPhraseStartPos);

							nextWordStartPos = r3::StringUtils::findNextPosNotInCharSet(currSourceLine, nextSpacePos, SFML_TEXT_WHITESPACE_CHAR_SET);
						}

						doneFlag = (nextWordStartPos > currSourceLine.size());
					}

					outputLineList.push_back(currPhrase);
				}
			}

			sf::Text alignmentText = this->fontFamily->createTextWithTypesetting(this->typesettingDefn);
			alignmentText.setScale(this->textBlockRegionDefn.scale);
			alignmentText.setRotation(this->textBlockRegionDefn.rotationDegrees);
			sf::Vector2f lineHeight = r3::sfml::TextUtils::resolveLineHeight(alignmentText);

			sf::Vector2f currAlignmentPosition = this->textBlockRegionDefn.position;
			if (this->textBlockRegionDefn.verticalAlignment == VerticalAlignment::MIDDLE) {
				currAlignmentPosition -= ((lineHeight * (float)outputLineList.size()) / 2.0f);
			}
			else if ( this->textBlockRegionDefn.verticalAlignment == VerticalAlignment::BOTTOM ) {
				currAlignmentPosition -= (lineHeight * (float)outputLineList.size());
			}

			std::vector<sf::Text> result;
			for (const auto& currOutputLine : outputLineList) {
				alignmentText.setString(currOutputLine);

				sf::Vector2f startLinePos = alignmentText.findCharacterPos(0);
				sf::Vector2f endLinePos = alignmentText.findCharacterPos(currOutputLine.size());
				sf::Vector2f lineVector = endLinePos - startLinePos;

				sf::Vector2f linePosition = currAlignmentPosition;
				if (this->textBlockRegionDefn.textAlignment == TextAlignment::CENTER) {
					linePosition = linePosition - (lineVector / 2.0f);
				}
				else if (this->textBlockRegionDefn.textAlignment == TextAlignment::RIGHT) {
					linePosition = linePosition - lineVector;
				}

				if (this->roundingCorrectionFlag) {
					linePosition.x = roundf(linePosition.x);
					linePosition.y = roundf(linePosition.y);
				}

				sf::Text currOutputText = this->fontFamily->createTextWithTypesetting(this->typesettingDefn);
				currOutputText.setString(currOutputLine);
				currOutputText.setPosition(linePosition);
				currOutputText.setScale(this->textBlockRegionDefn.scale);
				currOutputText.setRotation(this->textBlockRegionDefn.rotationDegrees);

				result.push_back(currOutputText);

				currAlignmentPosition += lineHeight;
			}

			return result;
		}

	}

}
