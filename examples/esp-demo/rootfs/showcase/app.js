/******/ (function() { // webpackBootstrap
/******/ 	var __webpack_modules__ = ({

/***/ "./app.js?entry":
/*!**********************!*\
  !*** ./app.js?entry ***!
  \**********************/
/***/ (function(module, __unused_webpack_exports, __webpack_require__) {

var $app_script$ = __webpack_require__(/*! !!../../lib/script.js!../../node_modules/babel-loader?extends=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/babel.config.js!../../lib/resource-reference-script.js!../../lib/manifest-loader.js?path=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/sample/showcase/app.js!./app.js */ "../../lib/script.js!../../node_modules/babel-loader/lib/index.js?extends=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/babel.config.js!../../lib/resource-reference-script.js!../../lib/manifest-loader.js?path=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/sample/showcase/app.js!./app.js")
var options=$app_script$
 if ($app_script$.__esModule) {

        options = $app_script$.default;
 }
module.exports=new ViewModel(options);

/***/ }),

/***/ "../../lib/script.js!../../node_modules/babel-loader/lib/index.js?extends=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/babel.config.js!../../lib/resource-reference-script.js!../../lib/manifest-loader.js?path=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/sample/showcase/app.js!./app.js":
/*!*******************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************!*\
  !*** ../../lib/script.js!../../node_modules/babel-loader/lib/index.js?extends=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/babel.config.js!../../lib/resource-reference-script.js!../../lib/manifest-loader.js?path=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/sample/showcase/app.js!./app.js ***!
  \*******************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/
/***/ (function(module, exports, __webpack_require__) {

"use strict";


Object.defineProperty(exports, "__esModule", ({
  value: true
}));
exports["default"] = void 0;
var _default = exports["default"] = {
  onCreate: function onCreate() {
    console.info("Application onCreate");
  },
  onDestroy: function onDestroy() {
    console.info("Application onDestroy");
  }
};
;
(exports["default"] || module.exports).manifest = __webpack_require__(/*! !!../../lib/manifest-plugin.js!./manifest.json */ "../../lib/manifest-plugin.js!./manifest.json");

function requireModule(moduleName) {
  return requireNative(moduleName.slice(1));
}


/***/ }),

/***/ "../../lib/manifest-plugin.js!./manifest.json":
/*!****************************************************!*\
  !*** ../../lib/manifest-plugin.js!./manifest.json ***!
  \****************************************************/
/***/ (function(module) {

"use strict";
module.exports = JSON.parse('{"manifest.json":"content"}');

/***/ })

/******/ 	});
/************************************************************************/
/******/ 	// The module cache
/******/ 	var __webpack_module_cache__ = {};
/******/ 	
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/ 		// Check if module is in cache
/******/ 		var cachedModule = __webpack_module_cache__[moduleId];
/******/ 		if (cachedModule !== undefined) {
/******/ 			return cachedModule.exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = __webpack_module_cache__[moduleId] = {
/******/ 			// no module.id needed
/******/ 			// no module.loaded needed
/******/ 			exports: {}
/******/ 		};
/******/ 	
/******/ 		// Execute the module function
/******/ 		__webpack_modules__[moduleId](module, module.exports, __webpack_require__);
/******/ 	
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/ 	
/************************************************************************/
/******/ 	
/******/ 	// startup
/******/ 	// Load entry module and return exports
/******/ 	// This entry module is referenced by other modules so it can't be inlined
/******/ 	var __webpack_exports__ = __webpack_require__("./app.js?entry");
/******/ 	
/******/ 	return __webpack_exports__;
/******/ })()
;
//# sourceMappingURL=app.js.map