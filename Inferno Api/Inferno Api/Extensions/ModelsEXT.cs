using Assets.Scripts.Models;
using Assets.Scripts.Utils;
using UnhollowerBaseLib;

namespace Inferno.Extensions {
    public static class ModelsEXT {
        public static T Clone<T>(this T model) where T : Model => model.Clone().Cast<T>();

        public static T[] Clone<T>(this Il2CppArrayBase<T> models) where T : Model => Helpers.CloneArray(models);
    }
}