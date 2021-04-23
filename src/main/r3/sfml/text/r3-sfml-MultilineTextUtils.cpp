
#include <string>
#include <vector>
#include <r3/string/r3-string-utils.hpp>
#include <r3/sfml/text/r3-sfml-TextUtils.hpp>
#include <r3/sfml/text/r3-sfml-MultilineTextUtils.hpp>

namespace r3 {

	namespace sfml {

		namespace MultilineTextUtils {

			sf::Text buildText(const MultilineTextDefn& multilineTextDefn) {
				sf::Text result = multilineTextDefn.typesettingDefn.fontFamily->createTextWithStyle(multilineTextDefn.typesettingDefn.style);
				result.setCharacterSize(multilineTextDefn.typesettingDefn.characterSize);
				result.setLineSpacing(multilineTextDefn.typesettingDefn.lineSpacing);
				result.setLetterSpacing(multilineTextDefn.typesettingDefn.letterSpacing);
				result.setFillColor(multilineTextDefn.typesettingDefn.fillColor);
				result.setOutlineColor(multilineTextDefn.typesettingDefn.outlineColor);
				result.setOutlineThickness(multilineTextDefn.typesettingDefn.outlineThickness);

				std::vector<std::wstring> sourceLineList = r3::StringUtils::split(multilineTextDefn.string, L'\n');

				std::vector<std::wstring> outputLineList;

				for (auto& currLine : sourceLineList) {
					result.setString(currLine);
					float currLineWidth = r3::sfml::TextUtils::resolveTextWidth(result);

					if (currLineWidth <= multilineTextDefn.maxLineWidth) {
						outputLineList.push_back(currLine);
					}
					else {
						size_t nextWordStartPos = 0;
						size_t currPhraseStartPos = 0;
						std::wstring currPhrase;
						std::wstring lookAheadPhrase;

						bool doneFlag = false;
						while (!doneFlag) {
							size_t nextSpacePos = currLine.find(L' ', nextWordStartPos);

							if (nextSpacePos == std::wstring::npos) {
								nextSpacePos = currLine.size();
							}

							lookAheadPhrase = currLine.substr(currPhraseStartPos, nextSpacePos - currPhraseStartPos);
							result.setString(lookAheadPhrase);
							float lookAheadTextWidth = r3::sfml::TextUtils::resolveTextWidth(result);

							if (lookAheadTextWidth > multilineTextDefn.maxLineWidth) {
								if (currPhrase.empty()) {
									nextWordStartPos = nextSpacePos + 1;
								}
								else {
									outputLineList.push_back(currPhrase);

									currPhraseStartPos = nextWordStartPos;
									currPhrase.clear();
								}

							}
							else {
								currPhrase = currLine.substr(currPhraseStartPos, nextSpacePos - currPhraseStartPos);

								nextWordStartPos = nextSpacePos + 1;
							}

							doneFlag = (nextWordStartPos > currLine.size());
						}

						outputLineList.push_back(currPhrase);
					}
				}
				
				result.setString(r3::StringUtils::join(outputLineList, L'\n'));

				// TODO: actually, need to return an array of Text objects, in order to handle alignment issues!

				result.setPosition(multilineTextDefn.position);
				result.setScale(multilineTextDefn.scale);
				result.setRotation(multilineTextDefn.rotationDegrees);

				return result;
			}

		}

	}

}
