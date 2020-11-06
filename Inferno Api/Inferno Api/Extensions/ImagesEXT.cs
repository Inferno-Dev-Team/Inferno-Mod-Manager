using System.Drawing;

namespace Inferno.Extensions {
    public static class Images {
        public static byte[] ToByteArray(this Bitmap b) => (byte[]) new ImageConverter().ConvertTo(b, typeof(byte[]));
    }
}