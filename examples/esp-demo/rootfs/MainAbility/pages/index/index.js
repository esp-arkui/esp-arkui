/******/ (function() { // webpackBootstrap
/******/ 	var __webpack_modules__ = ({

/***/ 538:
/***/ (function(module, __unused_webpack_exports, __webpack_require__) {

var $app_template$ = __webpack_require__(672)
var $app_style$ = __webpack_require__(680)
var $app_script$ = __webpack_require__(465)
var options=$app_script$
 if ($app_script$.__esModule) {

      options = $app_script$.default;
 }
options.styleSheet=$app_style$
options.render=$app_template$;
module.exports=new ViewModel(options);

/***/ }),

/***/ 680:
/***/ (function(module) {

module.exports = {"classSelectors":{"container":{"width":"100%","height":"100%","justifyContent":"center","alignItems":"center"},"title":{"width":200,"fontSize":30,"textAlign":"center"}}}

/***/ }),

/***/ 672:
/***/ (function(module) {

module.exports = function (vm) { var _vm = vm || this; var i18ns = []; i18ns.push( _vm.$t('strings.hello') ); return _c('div', {'staticClass' : ["container"]} , [_c('text', {'attrs' : {'value' : function () {return (i18ns[0])+ decodeURI('') +decodeURI('%20')+ decodeURI('') +(_vm.title)+ decodeURI('') +decodeURI('%0A%20%20%20%20%20%20%20%20%E4%B9%90%E9%91%AB%E7%A7%91%E6%8A%80')}},'staticClass' : ["title"]} )] ) }

/***/ }),

/***/ 465:
/***/ (function(__unused_webpack_module, exports) {

"use strict";


Object.defineProperty(exports, "__esModule", ({
  value: true
}));
exports["default"] = void 0;
var _default = {
  data: {
    title: ''
  },
  onInit: function onInit() {
    this.title = this.$t('strings.world');
  }
};
exports["default"] = _default;

function requireModule(moduleName) {
  return requireNative(moduleName.slice(1));
}


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
/******/ 	var __webpack_exports__ = __webpack_require__(538);
/******/ 	
/******/ 	return __webpack_exports__;
/******/ })()
;
//# sourceMappingURL=index.js.map