(function(){/*

 Copyright The Closure Library Authors.
 SPDX-License-Identifier: Apache-2.0
*/
'use strict';var aa=this||self;function f(a,b){a=a.split(".");var c=aa;a[0]in c||"undefined"==typeof c.execScript||c.execScript("var "+a[0]);for(var d;a.length&&(d=a.shift());)a.length||void 0===b?c[d]&&c[d]!==Object.prototype[d]?c=c[d]:c=c[d]={}:c[d]=b}
function h(a,b){function c(){}c.prototype=b.prototype;a.u=b.prototype;a.prototype=new c;a.prototype.constructor=a;a.m=function(d,g,e){for(var n=Array(arguments.length-2),w=2;w<arguments.length;w++)n[w-2]=arguments[w];return b.prototype[g].apply(d,n)}};(class{constructor(a,b){this.g=b===ba?a:""}}).prototype.toString=function(){return this.g.toString()};var ba={};function k(){}var ca="function"==typeof Uint8Array;function l(a,b,c){a.h=null;b||(b=[]);a.s=void 0;a.j=-1;a.g=b;a:{if(b=a.g.length){--b;var d=a.g[b];if(!(null===d||"object"!=typeof d||Array.isArray(d)||ca&&d instanceof Uint8Array)){a.l=b-a.j;a.i=d;break a}}a.l=Number.MAX_VALUE}a.o={};if(c)for(b=0;b<c.length;b++)d=c[b],d<a.l?(d+=a.j,a.g[d]=a.g[d]||m):(p(a),a.i[d]=a.i[d]||m)}var m=[];function p(a){var b=a.l+a.j;a.g[b]||(a.i=a.g[b]={})}
function q(a,b){if(b<a.l){b+=a.j;var c=a.g[b];return c!==m?c:a.g[b]=[]}if(a.i)return c=a.i[b],c===m?a.i[b]=[]:c}function r(a,b){a=q(a,b);return null==a?a:!!a}function da(a){a=q(a,3);return null==a?0:a}function t(a,b){a=r(a,b);return null==a?!1:a}function u(a,b,c){b<a.l?a.g[b+a.j]=c:(p(a),a.i[b]=c);return a}function v(a,b,c,d){c!==d?u(a,b,c):b<a.l?a.g[b+a.j]=null:(p(a),delete a.i[b]);return a}function x(a,b,c){a.h||(a.h={});if(!a.h[c]){var d=q(a,c);d&&(a.h[c]=new b(d))}return a.h[c]}
function y(a,b,c){a.h||(a.h={});let d=c?z(c):c;a.h[b]=c;return u(a,b,d)}function z(a){if(a.h)for(var b in a.h){var c=a.h[b];if(Array.isArray(c))for(var d=0;d<c.length;d++)c[d]&&z(c[d]);else c&&z(c)}return a.g}function A(a,b){return new a(b?JSON.parse(b):null)}k.prototype.toString=function(){return z(this).toString()};function B(a){l(this,a,ea)}h(B,k);var ea=[17];function C(a){l(this,a,fa)}h(C,k);var fa=[8];function D(a){l(this,a,ha)}h(D,k);var ha=[27];function E(a){l(this,a,ia)}h(E,k);var ia=[1,2,3];function F(a){l(this,a,null)}h(F,k);function G(a){l(this,a,null)}h(G,k);function H(a){l(this,a,ja)}h(H,k);function I(a){l(this,a,null)}h(I,k);var ja=[13];function J(a){l(this,a,null)}h(J,k);function K(a){l(this,a,ka)}h(K,k);var ka=[12];function L(a,b){a=a.getElementsByTagName("META");for(let c=0;c<a.length;++c)if(a[c].getAttribute("name")===b)return a[c].getAttribute("content")||"";return""};function M(a,b){b=new CustomEvent(b);a.body.dispatchEvent(b)}
var la=class{constructor(a){this.body=a;var b=L(a,"namespace");if(!b){b="ns-"+Math.random().toString(36).substr(2,5);a:{var c=a.getElementsByTagName("META");for(let d=0;d<c.length;++d)if("namespace"===c[d].getAttribute("name")&&c[d].getAttribute("index")===(0).toString()){c[d].setAttribute("content",b);break a}c=a.querySelector("#mys-meta");c||(c=document.createElement("div"),c.id="mys-meta",c.style.position="absolute",c.style.display="none",a.appendChild(c));a=document.createElement("META");a.setAttribute("name",
"namespace");a.setAttribute("content",b);a.setAttribute("index",(0).toString());c.appendChild(a)}}}};function N(a){var b=document;a=String(a);"application/xhtml+xml"===b.contentType&&(a=a.toLowerCase());return b.createElement(a)};function O(a){if(1>=a.h.offsetWidth||1>=a.h.offsetHeight)return!1;a.g.remove();M(a.i,"spanReady");return!0}
class ma{constructor(a,b){this.i=a;this.j=b;this.h=N("SPAN");this.h.style.fontSize="6px";this.h.textContent="go";this.g=N("DIV");this.g.style.position="absolute";this.g.style.top="100%";this.g.style.left="100%";this.g.style.width="1px";this.g.style.height="0";this.g.style.overflow="hidden";this.g.style.visibility="hidden";this.g.appendChild(this.h)}wait(){if(t(this.j,1))return null;M(this.i,"spanStart");this.i.body.appendChild(this.g);return O(this)?null:new Promise(a=>{const b=setInterval(()=>{O(this)&&
(clearInterval(b),a())},da(this.j))})}};function P(a){a.h&=-31}function Q(a,b){a.h|=b}class na{constructor(a,b){this.g=a;this.i=b;new K;this.h=0}j(){}};function R(a,b,c){if(b&&c){const d=x(a.g.i,H,6);v(d,2,b,0);v(d,3,c,0)}A(E,L(a.h.body,"engine_msg")||"[]");return a.g.j()||Promise.resolve()}function oa(a){P(a.g);Q(a.g,1);window.AFMA_Communicator&&window.AFMA_Communicator.addEventListener("onshow",()=>{Q(a.g,32)});let b=0;const c=a.h.body;c.addEventListener("browserRender",()=>{++b;if(1==b)M(a.h,"overallStart"),R(a).then(()=>{M(a.h,"overallQuiet")});else{var d=c.clientWidth,g=c.clientHeight;d&&g&&R(a,d,g)}})}
class pa{constructor(a,b,c){this.h=new la(a);a=new J(b);this.g=c(this.h,a)}};function qa(a){a.i.length=0;a.h=!0}function S(a,b=null){a.g=!0;const c=()=>{a.h=!1;const d=a.i.shift();return void 0===d?(a.g=!1,Promise.resolve()):S(a,d())};return b?b.then(c,()=>{if(a.h)return c();a.g=!1;return Promise.reject()}):c()}function ra(a,b){for(const c of b)a.i.push(c);return a.g?null:S(a)}class sa{constructor(){this.h=this.g=!1;this.i=[]}};var T={};function U(){if(T!==T)throw Error("Bad secret");};function V(){var a="undefined"!==typeof window?window.trustedTypes:void 0;return null!==a&&void 0!==a?a:null};var W,ta=class{};class ua extends ta{constructor(){var a=null!==X&&void 0!==X?X:"";super();U();this.g=a}toString(){return this.g.toString()}}var X=null===(W=V())||void 0===W?void 0:W.emptyHTML;new ua;var Y,va=class{};class wa extends va{constructor(){var a=null!==Z&&void 0!==Z?Z:"";super();U();this.g=a}toString(){return this.g.toString()}}var Z=null===(Y=V())||void 0===Y?void 0:Y.emptyScript;new wa;var xa=class{};class ya extends xa{constructor(a){super();U();this.g=a}toString(){return this.g}}new ya("about:blank");new ya("about:invalid#zTSz");class za extends na{constructor(a,b){super(a,b);this.l=new sa}j(){qa(this.l);return ra(this.l,[()=>null,()=>{{var a=null;const b=x(x(this.i,H,6),G,1);b&&(a=(new ma(this.g,b)).wait());M(this.g,"browserStart");M(this.g,"browserStartEnd");P(this);Q(this,2)}return a},()=>{M(this.g,"browserReady");M(this.g,"browserReadyEnd");Q(this,4);M(this.g,"overallReady");return null},()=>{M(this.g,"browserQuiet");M(this.g,"browserQuietEnd");Q(this,8);return null}])}}
(function(a){let b=null;f("mys.engine.init",(c,d)=>{c=A(J,L(d,"render_config")||"[]");b=new pa(d,z(c),a);oa(b)});f("mys.engine.stage",()=>b?b.g.h:0)})(function(a,b){if(null!=q(b,6))var c=x(b,H,6);else{c=x(b,D,1);var d=x(b,C,12)||new C;var g=new I;var e=q(c,42);e=null==e?e:+e;g=v(g,1,(null==e?0:e)||1,0);r(d,18)&&v(g,2,!0,!1);r(d,19)&&v(g,3,!0,!1);e=new H;var n=r(d,6)||!1;e=v(e,10,n,!1);n=q(d,2)||0;e=v(e,7,n,0);n=r(d,15)||!1;e=v(e,18,n,!1);g=y(e,23,g);e=q(d,20)||0;0<e&&v(g,24,e,0);e=new G;e=v(e,3,100,
0);e=v(e,4,1E4,0);r(d,4)?(v(e,6,!0,!1),v(e,7,"monospace",""),v(e,8,"IMWimw0.!?@","")):(r(d,5)&&v(e,9,!0,!1),v(e,5,!0,!1));y(g,1,e);e=new F;x(c,B,10)&&t(x(c,B,10),6)&&v(e,1,!0,!1);t(c,16)&&!r(d,1)&&v(e,2,!0,!1);(c=q(d,22))&&v(e,3,c,"");y(g,4,e);c=g}y(b,6,c);return new za(a,b)});}).call(this);