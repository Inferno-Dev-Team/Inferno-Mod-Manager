using Assets.Scripts.Models;
using Assets.Scripts.Models.Towers;
using Assets.Scripts.Models.Towers.Behaviors.Attack;
using System.Linq;
using UnhollowerRuntimeLib;

namespace Inferno.Extensions {
    public static class TowerModelEXT {
        #region Common extension functions

        #region Getting behaviors extension functions
        public static Model GetBehaviorModel(this TowerModel towerModel, int index) =>
            towerModel.behaviors[index];
        public static T GetBehaviorModel<T>(this TowerModel towerModel, int index) where T : Model =>
            towerModel.GetBehaviorModel(index).Cast<T>();
        public static Model GetBehaviorModel(this TowerModel towerModel, string partialName, int number = 0) =>
            towerModel.behaviors.GetModels(partialName).ElementAtOrDefault(number);
        public static T GetBehaviorModel<T>(this TowerModel towerModel, string partialName, int number = 0) where T : Model =>
            towerModel.GetBehaviorModel(partialName, number).Cast<T>();
        public static Model GetBehaviorModel(this TowerModel towerModel, int number, params string[] partialNames) =>
            towerModel.behaviors.GetModels(partialNames).ElementAtOrDefault(number);
        public static T GetBehaviorModel<T>(this TowerModel towerModel, int number, params string[] partialNames) where T : Model =>
            towerModel.GetBehaviorModel(number, partialNames).Cast<T>();

        public static Model[] GetBehaviorModels(this TowerModel towerModel, params int[] indices) =>
            towerModel.behaviors.GetModels(indices);
        public static Model[] GetBehaviorModels(this TowerModel towerModel, int start, int length) =>
            towerModel.behaviors.GetModels(start, length);
        public static Model[] GetBehaviorModels(this TowerModel towerModel, string partialName) =>
            towerModel.behaviors.GetModels(partialName);
        public static Model[] GetBehaviorModels(this TowerModel towerModel, params string[] partialNames) =>
            towerModel.behaviors.GetModels(partialNames);
        #endregion

        #region Getting indices extension functions
        public static int GetBehaviorModelIndex<T>(this TowerModel towerModel, T behavior) where T : Model =>
            towerModel.behaviors.GetModelIndex(behavior);
        public static int GetBehaviorModelIndex(this TowerModel towerModel, string partialName, int number = 0) =>
            towerModel.behaviors.GetModelIndex(partialName, number);
        public static int GetModelIndex(this TowerModel towerModel, int number, params string[] partialNames) =>
            towerModel.behaviors.GetModelIndex(number, partialNames);

        public static int[] GetBehaviorModelIndices<T>(this TowerModel towerModel, params T[] behaviors) where T : Model =>
            towerModel.behaviors.GetModelIndices(behaviors);
        public static int[] GetBehaviorModelIndices(this TowerModel towerModel, string partialName) =>
            towerModel.behaviors.GetModelIndices(partialName);
        public static int[] GetBehaviorModelIndices(this TowerModel towerModel, params string[] partialNames) =>
            towerModel.behaviors.GetModelIndices(partialNames);
        #endregion

        #region Adding behaviors extension functions
        public static void AddBehaviorModel<T>(this TowerModel towerModel, T behavior, int index = 0) where T : Model =>
            towerModel.behaviors = towerModel.behaviors.AddModel(behavior);

        public static void AddBehaviorModels<T>(this TowerModel towerModel, int index, params T[] behaviors) where T : Model =>
            towerModel.behaviors = towerModel.behaviors.AddModels(index, behaviors);
        #endregion

        #region Removing behaviors extension functions
        public static void RemoveBehaviorModel<T>(this TowerModel towerModel, T behavior) where T : Model =>
            towerModel.behaviors = towerModel.behaviors.RemoveModel(behavior);
        public static void RemoveBehaviorModel(this TowerModel towerModel, int index) =>
            towerModel.behaviors = towerModel.behaviors.RemoveModel(index);
        public static void RemoveBehaviorModel(this TowerModel towerModel, string partialName, int number = 0) =>
            towerModel.behaviors = towerModel.behaviors.RemoveModel(partialName, number);
        public static void RemoveBehaviorModel(this TowerModel towerModel, int number, params string[] partialNames) =>
            towerModel.behaviors = towerModel.behaviors.RemoveModel(number, partialNames);

        public static void RemoveBehaviorModels<T>(this TowerModel towerModel, params T[] behaviors) where T : Model =>
            towerModel.behaviors = towerModel.behaviors.RemoveModels(behaviors);
        public static void RemoveBehaviorModels(this TowerModel towerModel, params int[] indices) =>
            towerModel.behaviors = towerModel.behaviors.RemoveModels(indices);
        public static void RemoveBehaviorModels(this TowerModel towerModel, int start, int length) =>
            towerModel.behaviors = towerModel.behaviors.RemoveModels(start, length);
        public static void RemoveBehaviorModels(this TowerModel towerModel, string partialName) =>
            towerModel.behaviors = towerModel.behaviors.RemoveModels(partialName);
        public static void RemoveBehaviorModels(this TowerModel towerModel, params string[] partialNames) =>
            towerModel.behaviors = towerModel.behaviors.RemoveModels(partialNames);
        #endregion

        #region Copying behaviors extension functions
        public static Model CopyBehaviorModel(this TowerModel towerModel, int index) =>
            towerModel.behaviors.CopyModel(index);
        public static T CopyBehaviorModel<T>(this TowerModel towerModel, int index) where T : Model =>
            towerModel.CopyBehaviorModel(index).Cast<T>();
        public static Model CopyBehaviorModel(this TowerModel towerModel, string partialName, int number = 0) =>
            towerModel.behaviors.CopyModel(partialName, number);
        public static T CopyBehaviorModel<T>(this TowerModel towerModel, string partialName, int number = 0) where T : Model =>
            towerModel.CopyBehaviorModel(partialName, number).Cast<T>();
        public static Model CopyBehaviorModel(this TowerModel towerModel, int number, params string[] partialNames) =>
            towerModel.behaviors.CopyModel(number, partialNames);
        public static T CopyBehaviorModel<T>(this TowerModel towerModel, int number, params string[] partialNames) where T : Model =>
            towerModel.CopyBehaviorModel(number, partialNames).Cast<T>();

        public static Model[] CopyBehaviorModels(this TowerModel towerModel) =>
            towerModel.behaviors.CopyModels();
        public static Model[] CopyBehaviorModels(this TowerModel towerModel, params int[] indices) =>
            towerModel.behaviors.CopyModels(indices);
        public static Model[] CopyBehaviorModels(this TowerModel towerModel, int start, int length) =>
            towerModel.behaviors.CopyModels(start, length);
        public static Model[] CopyBehaviorModels(this TowerModel towerModel, string partialName) =>
            towerModel.behaviors.CopyModels(partialName);
        public static Model[] CopyBehaviorModels(this TowerModel towerModel, params string[] partialNames) =>
            towerModel.behaviors.CopyModels(partialNames);
        #endregion

        #region Checking has extension functions
        public static bool HasBehaviorModel<T>(this TowerModel towerModel, T behavior) where T : Model =>
            towerModel.behaviors.ContainsModel(behavior);
        public static bool HasBehaviorModel(this TowerModel towerModel, string partialName) =>
            towerModel.behaviors.ContainsModel(partialName);
        public static bool HasBehaviorModel(this TowerModel towerModel, params string[] partialNames) =>
            towerModel.behaviors.ContainsModel(partialNames);

        public static bool HasBehaviorModels<T>(this TowerModel towerModel, params T[] behaviors) where T : Model =>
            towerModel.behaviors.ContainsModels(behaviors);
        public static bool HasBehaviorModels(this TowerModel towerModel, params string[] partialNames) =>
            towerModel.behaviors.ContainsModels(partialNames);
        #endregion

        #endregion

        #region Unique extension functions

        public static AttackModel GetAttackModel(this TowerModel towerModel, int attackNumber = 0) {
            if (towerModel.HasBehaviorModel("AttackModel"))
                return towerModel.GetBehaviorModel<AttackModel>("AttackModel");
            return towerModel.GetBehaviorModel<AttackAirUnitModel>("AttackAirUnitModel");
        }

        #endregion
    }
}
