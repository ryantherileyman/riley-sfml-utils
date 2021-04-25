
#include <assert.h>
#include <iostream>
#include <math.h>
#include <r3/sfml/text/r3-sfml-FontFamily.hpp>

using namespace r3::sfml;

FontFamily createBaseOnlyFontFamily() {
	LoadFontFamilyDefn loadDefn;
	loadDefn.baseFontFilename = "OpenSans-Regular.ttf";

	FontFamily result;
	result.load(loadDefn);

	return result;
}

bool testCreateTextWithStyle_BaseOnly_FontReferences() {
	FontFamily fontFamily = createBaseOnlyFontFamily();

	sf::Text regularText = fontFamily.createTextWithStyle(sf::Text::Regular);
	sf::Text boldText = fontFamily.createTextWithStyle(sf::Text::Bold);
	sf::Text italicText = fontFamily.createTextWithStyle(sf::Text::Italic);
	sf::Text boldItalicText = fontFamily.createTextWithStyle(sf::Text::Bold | sf::Text::Italic);

	bool result =
		(regularText.getFont() == boldText.getFont()) &&
		(regularText.getFont() == italicText.getFont()) &&
		(regularText.getFont() == boldItalicText.getFont());
	return result;
}

bool testCreateTextWithStyle_BaseOnly_Style(sf::Uint32 inputStyle) {
	FontFamily fontFamily = createBaseOnlyFontFamily();

	sf::Text text = fontFamily.createTextWithStyle(inputStyle);

	bool result = (text.getStyle() == inputStyle);
	return result;
}

FontFamily createWithBoldFontFamily() {
	LoadFontFamilyDefn loadDefn;
	loadDefn.baseFontFilename = "OpenSans-Regular.ttf";
	loadDefn.boldFontFilename = "OpenSans-Bold.ttf";

	FontFamily result;
	result.load(loadDefn);

	return result;
}

bool testCreateTextWithStyle_WithBold_FontReferences() {
	FontFamily fontFamily = createWithBoldFontFamily();

	sf::Text regularText = fontFamily.createTextWithStyle(sf::Text::Regular);
	sf::Text boldText = fontFamily.createTextWithStyle(sf::Text::Bold);
	sf::Text italicText = fontFamily.createTextWithStyle(sf::Text::Italic);
	sf::Text boldItalicText = fontFamily.createTextWithStyle(sf::Text::Bold | sf::Text::Italic);

	bool result =
		(regularText.getFont() != boldText.getFont()) &&
		(regularText.getFont() == italicText.getFont()) &&
		(regularText.getFont() != boldItalicText.getFont()) &&
		(boldText.getFont() != italicText.getFont()) &&
		(boldText.getFont() == boldItalicText.getFont()) &&
		(italicText.getFont() != boldItalicText.getFont());
	return result;
}

bool testCreateTextWithStyle_WithBold_Style(sf::Uint32 inputStyle, sf::Uint32 expectedTextStyle) {
	FontFamily fontFamily = createWithBoldFontFamily();

	sf::Text text = fontFamily.createTextWithStyle(inputStyle);

	bool result = (text.getStyle() == expectedTextStyle);
	return result;
}

FontFamily createWithItalicFontFamily() {
	LoadFontFamilyDefn loadDefn;
	loadDefn.baseFontFilename = "OpenSans-Regular.ttf";
	loadDefn.italicFontFilename = "OpenSans-Italic.ttf";

	FontFamily result;
	result.load(loadDefn);

	return result;
}

bool testCreateTextWithStyle_WithItalic_FontReferences() {
	FontFamily fontFamily = createWithItalicFontFamily();

	sf::Text regularText = fontFamily.createTextWithStyle(sf::Text::Regular);
	sf::Text boldText = fontFamily.createTextWithStyle(sf::Text::Bold);
	sf::Text italicText = fontFamily.createTextWithStyle(sf::Text::Italic);
	sf::Text boldItalicText = fontFamily.createTextWithStyle(sf::Text::Bold | sf::Text::Italic);

	bool result =
		(regularText.getFont() == boldText.getFont()) &&
		(regularText.getFont() != italicText.getFont()) &&
		(regularText.getFont() != boldItalicText.getFont()) &&
		(italicText.getFont() != boldText.getFont()) &&
		(italicText.getFont() == boldItalicText.getFont()) &&
		(boldText.getFont() != boldItalicText.getFont());
	return result;
}

bool testCreateTextWithStyle_WithItalic_Style(sf::Uint32 inputStyle, sf::Uint32 expectedTextStyle) {
	FontFamily fontFamily = createWithItalicFontFamily();

	sf::Text text = fontFamily.createTextWithStyle(inputStyle);

	bool result = (text.getStyle() == expectedTextStyle);
	return result;
}

FontFamily createWithBoldItalicFontFamily() {
	LoadFontFamilyDefn loadDefn;
	loadDefn.baseFontFilename = "OpenSans-Regular.ttf";
	loadDefn.boldItalicFontFilename = "OpenSans-BoldItalic.ttf";

	FontFamily result;
	result.load(loadDefn);

	return result;
}

bool testCreateTextWithStyle_WithBoldItalic_FontReferences() {
	FontFamily fontFamily = createWithBoldItalicFontFamily();

	sf::Text regularText = fontFamily.createTextWithStyle(sf::Text::Regular);
	sf::Text boldText = fontFamily.createTextWithStyle(sf::Text::Bold);
	sf::Text italicText = fontFamily.createTextWithStyle(sf::Text::Italic);
	sf::Text boldItalicText = fontFamily.createTextWithStyle(sf::Text::Bold | sf::Text::Italic);

	bool result =
		(regularText.getFont() == boldText.getFont()) &&
		(regularText.getFont() == italicText.getFont()) &&
		(regularText.getFont() != boldItalicText.getFont()) &&
		(boldText.getFont() == italicText.getFont()) &&
		(boldText.getFont() != boldItalicText.getFont()) &&
		(italicText.getFont() != boldItalicText.getFont());
	return result;
}

bool testCreateTextWithStyle_WithBoldItalic_Style(sf::Uint32 inputStyle, sf::Uint32 expectedTextStyle) {
	FontFamily fontFamily = createWithBoldItalicFontFamily();

	sf::Text text = fontFamily.createTextWithStyle(inputStyle);

	bool result = (text.getStyle() == expectedTextStyle);
	return result;
}

FontFamily createWithAllFontFamily() {
	LoadFontFamilyDefn loadDefn;
	loadDefn.baseFontFilename = "OpenSans-Regular.ttf";
	loadDefn.boldFontFilename = "OpenSans-Bold.ttf";
	loadDefn.italicFontFilename = "OpenSans-Italic.ttf";
	loadDefn.boldItalicFontFilename = "OpenSans-BoldItalic.ttf";

	FontFamily result;
	result.load(loadDefn);

	return result;
}

bool testCreateTextWithStyle_WithAll_FontReferences() {
	FontFamily fontFamily = createWithAllFontFamily();

	sf::Text regularText = fontFamily.createTextWithStyle(sf::Text::Regular);
	sf::Text boldText = fontFamily.createTextWithStyle(sf::Text::Bold);
	sf::Text italicText = fontFamily.createTextWithStyle(sf::Text::Italic);
	sf::Text boldItalicText = fontFamily.createTextWithStyle(sf::Text::Bold | sf::Text::Italic);

	bool result =
		(regularText.getFont() != boldText.getFont()) &&
		(regularText.getFont() != italicText.getFont()) &&
		(regularText.getFont() != boldItalicText.getFont()) &&
		(boldText.getFont() != italicText.getFont()) &&
		(boldText.getFont() != boldItalicText.getFont()) &&
		(italicText.getFont() != boldItalicText.getFont());
	return result;
}

bool testCreateTextWithStyle_WithAll_Style(sf::Uint32 inputStyle, sf::Uint32 expectedTextStyle) {
	FontFamily fontFamily = createWithAllFontFamily();

	sf::Text text = fontFamily.createTextWithStyle(inputStyle);

	bool result = (text.getStyle() == expectedTextStyle);
	return result;
}

bool testCreateTextWithTypesetting() {
	FontFamily fontFamily = createWithAllFontFamily();

	TypesettingDefn typesetting;
	typesetting.characterSize = 16;
	typesetting.lineSpacing = 1.2f;
	typesetting.letterSpacing = 0.9f;
	typesetting.style = sf::Text::Bold | sf::Text::Underlined;
	typesetting.fillColor = sf::Color::Green;
	typesetting.outlineColor = sf::Color::Blue;
	typesetting.outlineThickness = 2.0f;

	sf::Text text = fontFamily.createTextWithTypesetting(typesetting);

	bool result =
		(text.getCharacterSize() == 16) &&
		(roundf(text.getLineSpacing() * 10) == 12) &&
		(roundf(text.getLetterSpacing() * 10) == 9) &&
		(text.getStyle() == sf::Text::Underlined) &&
		(text.getFillColor() == sf::Color::Green) &&
		(text.getOutlineColor() == sf::Color::Blue) &&
		(roundf(text.getOutlineThickness()) == 2);
	return result;
}

int main() {
	const sf::Uint32 boldItalicStyle = sf::Text::Bold | sf::Text::Italic;
	const sf::Uint32 everyStyle = sf::Text::Bold | sf::Text::Italic | sf::Text::StrikeThrough | sf::Text::Underlined;

	assert(testCreateTextWithStyle_BaseOnly_FontReferences());

	assert(testCreateTextWithStyle_BaseOnly_Style(sf::Text::Regular));
	assert(testCreateTextWithStyle_BaseOnly_Style(sf::Text::Bold));
	assert(testCreateTextWithStyle_BaseOnly_Style(sf::Text::Italic));
	assert(testCreateTextWithStyle_BaseOnly_Style(boldItalicStyle));
	assert(testCreateTextWithStyle_BaseOnly_Style(everyStyle));

	assert(testCreateTextWithStyle_WithBold_FontReferences());

	assert(testCreateTextWithStyle_WithBold_Style(sf::Text::Regular, sf::Text::Regular));
	assert(testCreateTextWithStyle_WithBold_Style(sf::Text::Bold, sf::Text::Regular));
	assert(testCreateTextWithStyle_WithBold_Style(sf::Text::Italic, sf::Text::Italic));
	assert(testCreateTextWithStyle_WithBold_Style(boldItalicStyle, sf::Text::Italic));
	assert(testCreateTextWithStyle_WithBold_Style(everyStyle, everyStyle - sf::Text::Bold));

	assert(testCreateTextWithStyle_WithItalic_FontReferences());

	assert(testCreateTextWithStyle_WithItalic_Style(sf::Text::Regular, sf::Text::Regular));
	assert(testCreateTextWithStyle_WithItalic_Style(sf::Text::Bold, sf::Text::Bold));
	assert(testCreateTextWithStyle_WithItalic_Style(sf::Text::Italic, sf::Text::Regular));
	assert(testCreateTextWithStyle_WithItalic_Style(boldItalicStyle, sf::Text::Bold));
	assert(testCreateTextWithStyle_WithItalic_Style(everyStyle, everyStyle - sf::Text::Italic));

	assert(testCreateTextWithStyle_WithBoldItalic_FontReferences());

	assert(testCreateTextWithStyle_WithBoldItalic_Style(sf::Text::Regular, sf::Text::Regular));
	assert(testCreateTextWithStyle_WithBoldItalic_Style(sf::Text::Bold, sf::Text::Bold));
	assert(testCreateTextWithStyle_WithBoldItalic_Style(sf::Text::Italic, sf::Text::Italic));
	assert(testCreateTextWithStyle_WithBoldItalic_Style(boldItalicStyle, sf::Text::Regular));
	assert(testCreateTextWithStyle_WithBoldItalic_Style(everyStyle, everyStyle - sf::Text::Bold - sf::Text::Italic));

	assert(testCreateTextWithStyle_WithAll_FontReferences());

	assert(testCreateTextWithStyle_WithAll_Style(sf::Text::Regular, sf::Text::Regular));
	assert(testCreateTextWithStyle_WithAll_Style(sf::Text::Bold, sf::Text::Regular));
	assert(testCreateTextWithStyle_WithAll_Style(sf::Text::Italic, sf::Text::Regular));
	assert(testCreateTextWithStyle_WithAll_Style(boldItalicStyle, sf::Text::Regular));
	assert(testCreateTextWithStyle_WithAll_Style(everyStyle, everyStyle - boldItalicStyle));

	assert(testCreateTextWithTypesetting());

	std::cout << "All tests passed!";
	return 0;
}
