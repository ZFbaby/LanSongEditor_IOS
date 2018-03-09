#import "LanSongTwoInputFilter.h"

@interface LanSongLookupFilter : LanSongTwoInputFilter
{
    GLint intensityUniform;
}

// How To Use:
// 1) Use your favourite photo editing application to apply a filter to lookup.png from LanSong/framework/Resources.
// For this to work properly each pixel color must not depend on other pixels (e.g. blur will not work).
// If you need more complex filter you can create as many lookup tables as required.
// E.g. color_balance_lookup_1.png -> LanSongGaussianBlurFilter -> color_balance_lookup_2.png
// 2) Use you new lookup.png file as a second input for LanSongLookupFilter.

// See LanSongAmatorkaFilter, LanSongMissEtikateFilter, and LanSongSoftEleganceFilter for example.

// Additional Info:
// Lookup texture is organised as 8x8 quads of 64x64 pixels representing all possible RGB colors:
//for (int by = 0; by < 8; by++) {
//    for (int bx = 0; bx < 8; bx++) {
//        for (int g = 0; g < 64; g++) {
//            for (int r = 0; r < 64; r++) {
//                image.setPixel(r + bx * 64, g + by * 64, qRgb((int)(r * 255.0 / 63.0 + 0.5),
//                                                              (int)(g * 255.0 / 63.0 + 0.5),
//                                                              (int)((bx + by * 8.0) * 255.0 / 63.0 + 0.5)));
//            }
//        }
//    }
//}

// Opacity/intensity of lookup filter ranges from 0.0 to 1.0, with 1.0 as the normal setting

/**
 第一个纹理和第二个纹理的混淆程度;
 如果是0,则完全用第一个纹理, 如果是1,则完全用第二个纹理;
 */
@property(readwrite, nonatomic) CGFloat intensity;

@end
