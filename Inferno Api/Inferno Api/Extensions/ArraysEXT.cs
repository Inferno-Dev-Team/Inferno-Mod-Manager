using Assets.Scripts.Models;
using Assets.Scripts.Utils;
using System.Linq;
using UnhollowerBaseLib;

namespace Inferno.Extensions {
    public static class ArraysEXT {
        #region Getting models extension functions
        public static B GetModel<B>(this Il2CppArrayBase<B> array, string partialName, int number = 0) where B : Model =>
            array.GetModels(partialName).ElementAtOrDefault(number);
        public static B GetModel<B>(this Il2CppArrayBase<B> array, int number, params string[] partialNames) where B : Model =>
            array.GetModels(partialNames).ElementAtOrDefault(number);

        public static B[] GetModels<B>(this Il2CppArrayBase<B> array, params int[] indices) where B : Model =>
            array.Where((b, i) => indices.Contains(i)).ToArray();
        public static B[] GetModels<B>(this Il2CppArrayBase<B> array, int start, int length) where B : Model =>
            array.Skip(start).Take(length).ToArray();
        public static B[] GetModels<B>(this Il2CppArrayBase<B> array, string partialName) where B : Model =>
            array.Where(b => b.Matches(partialName)).ToArray();
        public static B[] GetModels<B>(this Il2CppArrayBase<B> array, params string[] partialNames) where B : Model =>
            array.Where(b => b.MatchesAny(partialNames)).ToArray();
        #endregion

        #region Getting indices extension functions
        public static int GetModelIndex<B, T>(this Il2CppArrayBase<B> array, T model) where B : Model where T : B =>
            Helpers.IndexOf(array, array.Length, model);
        public static int GetModelIndex<B>(this Il2CppArrayBase<B> array, string partialName, int number = 0) where B : Model {
            int[] indices = array.GetModelIndices(partialName);
            if (number < indices.Length)
                return indices[number];
            return -1;
        }
        public static int GetModelIndex<B>(this Il2CppArrayBase<B> array, int number, params string[] partialNames) where B : Model {
            int[] indices = array.GetModelIndices(partialNames);
            if (number < indices.Length)
                return indices[number];
            return -1;
        }

        public static int[] GetModelIndices<B, T>(this Il2CppArrayBase<B> array, params T[] models) where B : Model where T : B =>
            array.Select((b, i) => b.IsAny(models) ? i : -1).Where(i => i > -1).ToArray();
        public static int[] GetModelIndices<B>(this Il2CppArrayBase<B> array, string partialName) where B : Model =>
            array.Select((b, i) => b.Matches(partialName) ? i : -1).Where(i => i > -1).ToArray();
        public static int[] GetModelIndices<B>(this Il2CppArrayBase<B> array, params string[] partialNames) where B : Model =>
            array.Select((b, i) => b.MatchesAny(partialNames) ? i : -1).Where(i => i > -1).ToArray();
        #endregion

        #region Adding extension functions
        public static B[] AddModel<B, T>(this Il2CppArrayBase<B> array, T model, int index = 0) where B : Model where T : B =>
            array.Take(index).Append(model).Concat(array.Skip(index)).ToArray();

        public static B[] AddModels<B, T>(this Il2CppArrayBase<B> array, int index, params T[] models) where B : Model where T : B =>
            array.Take(index).Concat(models).Concat(array.Skip(index)).ToArray();
        #endregion

        #region Removing extension functions
        public static B[] RemoveModel<B, T>(this Il2CppArrayBase<B> array, T model) where B : Model where T : B =>
            array.Where(b => !b.Is(model)).ToArray();
        public static B[] RemoveModel<B>(this Il2CppArrayBase<B> array, int index) where B : Model =>
            array.Where((b, i) => i != index).ToArray();
        public static B[] RemoveModel<B>(this Il2CppArrayBase<B> array, string partialName, int number = 0) where B : Model =>
            array.RemoveModel(array.GetModelIndex(partialName, number));
        public static B[] RemoveModel<B>(this Il2CppArrayBase<B> array, int number, params string[] partialNames) where B : Model =>
            array.RemoveModel(array.GetModelIndex(number, partialNames));

        public static B[] RemoveModels<B, T>(this Il2CppArrayBase<B> array, params T[] models) where B : Model where T : B =>
            array.Where(b => !b.IsAny(models)).ToArray();
        public static B[] RemoveModels<B>(this Il2CppArrayBase<B> array, params int[] indices) where B : Model =>
            array.Where((b, i) => !indices.Contains(i)).ToArray();
        public static B[] RemoveModels<B>(this Il2CppArrayBase<B> array, int start, int length) where B : Model =>
            array.Where((b, i) => i < start || i >= start + length).ToArray();
        public static B[] RemoveModels<B>(this Il2CppArrayBase<B> array, string partialName) where B : Model =>
            array.Where(b => !b.Matches(partialName)).ToArray();
        public static B[] RemoveModels<B>(this Il2CppArrayBase<B> array, params string[] partialNames) where B : Model =>
            array.Where(b => !b.MatchesAny(partialNames)).ToArray();
        #endregion

        #region Copying extension functions
        public static B CopyModel<B>(this Il2CppArrayBase<B> array, int index) where B : Model =>
            array[index].Copy();
        public static B CopyModel<B>(this Il2CppArrayBase<B> array, string partialName, int number = 0) where B : Model =>
            array.GetModel(partialName, number).Copy();
        public static B CopyModel<B>(this Il2CppArrayBase<B> array, int number, params string[] partialNames) where B : Model =>
            array.GetModel(number, partialNames).Copy();

        public static B[] CopyModels<B>(this Il2CppArrayBase<B> array) where B : Model =>
            Helpers.CloneArray(array);
        public static B[] CopyModels<B>(this Il2CppArrayBase<B> array, params int[] indices) where B : Model =>
            array.GetModels(indices).Select(b => b.Copy()).ToArray();
        public static B[] CopyModels<B>(this Il2CppArrayBase<B> array, int start, int length) where B : Model =>
            array.GetModels(start, length).Select(b => b.Copy()).ToArray();
        public static B[] CopyModels<B>(this Il2CppArrayBase<B> array, string partialName) where B : Model =>
            array.GetModels(partialName).Select(b => b.Copy()).ToArray();
        public static B[] CopyModels<B>(this Il2CppArrayBase<B> array, params string[] partialNames) where B : Model =>
            array.GetModels(partialNames).Select(b => b.Copy()).ToArray();
        #endregion

        #region Checking contains extension functions
        public static bool ContainsModel<B, T>(this Il2CppArrayBase<B> array, T model) where B : Model where T : B =>
            array.Any(b => b.Is(model));
        public static bool ContainsModel<B>(this Il2CppArrayBase<B> array, string partialName) where B : Model =>
            array.Any(b => b.Matches(partialName));
        public static bool ContainsModel<B>(this Il2CppArrayBase<B> array, params string[] partialNames) where B : Model =>
            array.Any(b => b.MatchesAny(partialNames));

        public static bool ContainsModels<B, T>(this Il2CppArrayBase<B> array, params T[] models) where B : Model where T : B =>
            models.All(m => array.Any(b => b.Is(m)));
        public static bool ContainsModels<B>(this Il2CppArrayBase<B> array, params string[] partialNames) where B : Model =>
            partialNames.All(pn => array.Any(b => b.Matches(pn)));
        #endregion
    }
}
