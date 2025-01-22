/******/ (function() { // webpackBootstrap
/******/ 	var __webpack_modules__ = ({

/***/ "./pages/index/index.hml?entry":
/*!*************************************!*\
  !*** ./pages/index/index.hml?entry ***!
  \*************************************/
/***/ (function(module, __unused_webpack_exports, __webpack_require__) {

var $app_template$ = __webpack_require__(/*! !!../../../../lib/json.js!../../../../lib/template.js!./index.hml */ "../../lib/json.js!../../lib/template.js!./pages/index/index.hml")
var $app_style$ = __webpack_require__(/*! !!../../../../lib/json.js!../../../../lib/style.js!./index.css */ "../../lib/json.js!../../lib/style.js!./pages/index/index.css")
var $app_script$ = __webpack_require__(/*! !!../../../../lib/script.js!../../../../node_modules/babel-loader?extends=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/babel.config.js!../../../../lib/resource-reference-script.js!./index.js */ "../../lib/script.js!../../node_modules/babel-loader/lib/index.js?extends=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/babel.config.js!../../lib/resource-reference-script.js!./pages/index/index.js")
var options=$app_script$
 if ($app_script$.__esModule) {

      options = $app_script$.default;
 }
options.styleSheet=$app_style$
options.render=$app_template$;
module.exports=new ViewModel(options);

/***/ }),

/***/ "../../lib/json.js!../../lib/style.js!./pages/index/index.css":
/*!********************************************************************!*\
  !*** ../../lib/json.js!../../lib/style.js!./pages/index/index.css ***!
  \********************************************************************/
/***/ (function(module) {

module.exports = {"classSelectors":{"separatorContainerStyle":{"width":454,"height":4,"backgroundColor":9145210},"titleContainerStyle":{"width":454,"height":70},"titleTextStyle":{"width":454,"height":50,"marginLeft":170,"marginTop":0},"buttonContainerStyle":{"width":454,"height":80},"buttonStyle":{"width":200,"height":60,"marginLeft":130}}}

/***/ }),

/***/ "../../lib/json.js!../../lib/template.js!./pages/index/index.hml":
/*!***********************************************************************!*\
  !*** ../../lib/json.js!../../lib/template.js!./pages/index/index.hml ***!
  \***********************************************************************/
/***/ (function(module) {

module.exports = function (vm) { var _vm = vm || this; return _c('list', {'staticStyle' : {'left' : 0,'top' : 0,'flexDirection' : "column",'width' : 454,'height' : 454}, } , [_c('list-item', {'staticStyle' : {'height' : 40,'width' : 454}, } ),_c('list-item', {'staticClass' : ["titleContainerStyle"]} , [_c('text', {'attrs' : {'value' : "功能展示"},'staticClass' : ["titleTextStyle"]} )] ),_c('list-item', {'staticClass' : ["separatorContainerStyle"]} ),_c('list-item', {'staticClass' : ["buttonContainerStyle"]} , [_c('input', {'attrs' : {'type' : "button",'value' : "容器组件"},'staticClass' : ["buttonStyle"],'onBubbleEvents' : {'click' : _vm.changeComponent1}} )] ),_c('list-item', {'staticClass' : ["separatorContainerStyle"]} ),_c('list-item', {'staticClass' : ["buttonContainerStyle"]} , [_c('input', {'attrs' : {'type' : "button",'value' : "基础组件"},'staticClass' : ["buttonStyle"],'onBubbleEvents' : {'click' : _vm.changeComponent2}} )] ),_c('list-item', {'staticClass' : ["separatorContainerStyle"]} ),_c('list-item', {'staticClass' : ["buttonContainerStyle"]} , [_c('input', {'attrs' : {'type' : "button",'value' : "表单组件"},'staticClass' : ["buttonStyle"],'onBubbleEvents' : {'click' : _vm.changeComponent3}} )] ),_c('list-item', {'staticClass' : ["separatorContainerStyle"]} ),_c('list-item', {'staticClass' : ["buttonContainerStyle"]} , [_c('input', {'attrs' : {'type' : "button",'value' : "其他"},'staticClass' : ["buttonStyle"],'onBubbleEvents' : {'click' : _vm.changeComponent4}} )] ),_c('list-item', {'staticClass' : ["separatorContainerStyle"]} ),_c('list-item', {'staticClass' : ["buttonContainerStyle"]} , [_c('input', {'attrs' : {'type' : "button",'value' : "退出"},'staticClass' : ["buttonStyle"],'onBubbleEvents' : {'click' : _vm.exit}} )] ),_c('list-item', {'staticStyle' : {'height' : 40,'width' : 454}, } )] ) }

/***/ }),

/***/ "./common/js/general.js":
/*!******************************!*\
  !*** ./common/js/general.js ***!
  \******************************/
/***/ (function(__unused_webpack_module, exports) {

"use strict";


Object.defineProperty(exports, "__esModule", ({
  value: true
}));
exports.routePage = exports.goPage = exports.eventCommon = exports.backPage = void 0;
var _system = _interopRequireDefault(requireModule("@system.router"));
function _interopRequireDefault(e) { return e && e.__esModule ? e : { "default": e }; }
/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

var backPage = exports.backPage = function backPage(superiorUri) {
  return {
    backMain: function backMain() {
      _system["default"].replace({
        uri: "pages/index/index"
      });
    },
    backSuperior: function backSuperior() {
      _system["default"].replace({
        uri: superiorUri
      });
    }
  };
};
var goPage = exports.goPage = function goPage(superiorUri) {
  return {
    goHome: function goHome() {
      _system["default"].replace({
        uri: "pages/index/index"
      });
    },
    goPrevious: function goPrevious() {
      _system["default"].replace({
        uri: superiorUri
      });
    }
  };
};
var routePage = exports.routePage = function routePage(page) {
  return {
    changePage: function changePage() {
      _system["default"].replace({
        uri: page
      });
    }
  };
};
var eventCommon = exports.eventCommon = function eventCommon() {
  return {
    text1: "点击事件未触发",
    text2: "长按事件未触发",
    text3: "swipe事件未触发",
    clickFunc: function clickFunc() {
      this.text1 = "点击事件已触发";
    },
    longpressFunc: function longpressFunc() {
      this.text2 = "长按事件已触发";
    },
    swipeFunc: function swipeFunc(e) {
      this.text3 = "swipe方向：" + e.direction;
    }
  };
};

function requireModule(moduleName) {
  return requireNative(moduleName.slice(1));
}


/***/ }),

/***/ "../../lib/script.js!../../node_modules/babel-loader/lib/index.js?extends=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/babel.config.js!../../lib/resource-reference-script.js!./pages/index/index.js":
/*!*************************************************************************************************************************************************************************************************************************************************!*\
  !*** ../../lib/script.js!../../node_modules/babel-loader/lib/index.js?extends=/home/wujg/git/community/OpenHarmonyOS/4.1.1/developtools/ace_js2bundle/ace-loader/babel.config.js!../../lib/resource-reference-script.js!./pages/index/index.js ***!
  \*************************************************************************************************************************************************************************************************************************************************/
/***/ (function(__unused_webpack_module, exports, __webpack_require__) {

"use strict";


var _interopRequireDefault = __webpack_require__(/*! @babel/runtime/helpers/interopRequireDefault */ "../../node_modules/@babel/runtime/helpers/interopRequireDefault.js");
Object.defineProperty(exports, "__esModule", ({
  value: true
}));
exports["default"] = void 0;
var _general = __webpack_require__(/*! ../../common/js/general */ "./common/js/general.js");
var _system = _interopRequireDefault(requireModule("@system.app"));
var _default = exports["default"] = {
  changeComponent1: (0, _general.routePage)("pages/component/index/containerIndex/index").changePage,
  changeComponent2: (0, _general.routePage)("pages/component/index/baseIndex/index").changePage,
  changeComponent3: (0, _general.routePage)("pages/component/index/formIndex/index").changePage,
  changeComponent4: (0, _general.routePage)("pages/component/index/otherIndex/index").changePage,
  exit: function exit() {
    _system["default"].terminate();
  }
};

function requireModule(moduleName) {
  return requireNative(moduleName.slice(1));
}


/***/ }),

/***/ "../../node_modules/@babel/runtime/helpers/interopRequireDefault.js":
/*!**************************************************************************!*\
  !*** ../../node_modules/@babel/runtime/helpers/interopRequireDefault.js ***!
  \**************************************************************************/
/***/ (function(module) {

"use strict";


function _interopRequireDefault(obj) {
  return obj && obj.__esModule ? obj : {
    "default": obj
  };
}
module.exports = _interopRequireDefault, module.exports.__esModule = true, module.exports["default"] = module.exports;

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
/******/ 	var __webpack_exports__ = __webpack_require__("./pages/index/index.hml?entry");
/******/ 	
/******/ 	return __webpack_exports__;
/******/ })()
;
//# sourceMappingURL=index.js.map