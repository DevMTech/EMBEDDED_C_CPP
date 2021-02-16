(function(){/*

 Copyright The Closure Library Authors.
 SPDX-License-Identifier: Apache-2.0
*/
'use strict';var h=this||self;function k(a,b,c){a=a.split(".");c=c||h;a[0]in c||"undefined"==typeof c.execScript||c.execScript("var "+a[0]);for(var d;a.length&&(d=a.shift());)a.length||void 0===b?c[d]&&c[d]!==Object.prototype[d]?c=c[d]:c=c[d]={}:c[d]=b}function l(){}function q(a){var b=typeof a;return"object"==b&&null!=a||"function"==b}function aa(a,b,c){return a.call.apply(a.bind,arguments)}
function ba(a,b,c){if(!a)throw Error();if(2<arguments.length){var d=Array.prototype.slice.call(arguments,2);return function(){var e=Array.prototype.slice.call(arguments);Array.prototype.unshift.apply(e,d);return a.apply(b,e)}}return function(){return a.apply(b,arguments)}}function r(a,b,c){Function.prototype.bind&&-1!=Function.prototype.bind.toString().indexOf("native code")?r=aa:r=ba;return r.apply(null,arguments)}
function ca(a,b){var c=Array.prototype.slice.call(arguments,1);return function(){var d=c.slice();d.push.apply(d,arguments);return a.apply(this,d)}}function t(a,b){function c(){}c.prototype=b.prototype;a.I=b.prototype;a.prototype=new c;a.prototype.constructor=a;a.da=function(d,e,f){for(var g=Array(arguments.length-2),n=2;n<arguments.length;n++)g[n-2]=arguments[n];return b.prototype[e].apply(d,g)}};function da(){return null};function ea(a,b,c){for(const d in a)b.call(c,a[d],d,a)}function v(a){const b={};for(const c in a)b[c]=a[c];return b}var fa="constructor hasOwnProperty isPrototypeOf propertyIsEnumerable toLocaleString toString valueOf".split(" ");function ha(a,b){let c,d;for(let e=1;e<arguments.length;e++){d=arguments[e];for(c in d)a[c]=d[c];for(let f=0;f<fa.length;f++)c=fa[f],Object.prototype.hasOwnProperty.call(d,c)&&(a[c]=d[c])}};var ia=String.prototype.trim?function(a){return a.trim()}:function(a){return/^[\s\xa0]*([\s\S]*?)[\s\xa0]*$/.exec(a)[1]};
function ja(a,b){let c=0;a=ia(String(a)).split(".");b=ia(String(b)).split(".");const d=Math.max(a.length,b.length);for(let g=0;0==c&&g<d;g++){var e=a[g]||"",f=b[g]||"";do{e=/(\d*)(\D*)(.*)/.exec(e)||["","","",""];f=/(\d*)(\D*)(.*)/.exec(f)||["","","",""];if(0==e[0].length&&0==f[0].length)break;c=ka(0==e[1].length?0:parseInt(e[1],10),0==f[1].length?0:parseInt(f[1],10))||ka(0==e[2].length,0==f[2].length)||ka(e[2],f[2]);e=e[3];f=f[3]}while(0==c)}return c}function ka(a,b){return a<b?-1:a>b?1:0};var w=class{constructor(a,b){this.g=b===la?a:""}};w.prototype.j=!0;w.prototype.h=function(){return this.g.toString()};w.prototype.toString=function(){return this.g.toString()};function ma(a){var b=String(a.substr(0,4)).toLowerCase();b="tel:"<b?-1:"tel:"==b?0:1;0==b||(a="about:invalid#zClosurez");return new w(a,la)}var na=/^(?:(?:https?|mailto|ftp):|[^:/?#]*(?:[/?#]|$))/i,la={};var x;a:{var oa=h.navigator;if(oa){var pa=oa.userAgent;if(pa){x=pa;break a}}x=""}function y(a){return-1!=x.indexOf(a)};function qa(){return y("Firefox")||y("FxiOS")}function ra(){return(y("Chrome")||y("CriOS"))&&!y("Edge")};function sa(a,b){b instanceof w||b instanceof w||(b="object"==typeof b&&b.j?b.h():String(b),na.test(b)||(b="about:invalid#zClosurez"),b=new w(b,la));a.href=b instanceof w&&b.constructor===w?b.g:"type_error:SafeUrl"};function ta(a){for(var b=0,c=0;c<a.length;++c)b=31*b+a.charCodeAt(c)>>>0;return b};function z(){return y("iPhone")&&!y("iPod")&&!y("iPad")};function ua(a){ua[" "](a);return a}ua[" "]=l;function va(a,b){try{return ua(a[b]),!0}catch(c){}return!1};var wa=y("Opera"),B=y("Trident")||y("MSIE"),xa=y("Edge"),ya=y("Gecko")&&!(-1!=x.toLowerCase().indexOf("webkit")&&!y("Edge"))&&!(y("Trident")||y("MSIE"))&&!y("Edge"),za=-1!=x.toLowerCase().indexOf("webkit")&&!y("Edge"),Aa=y("Macintosh"),Ba=y("Windows"),Ca=y("Android"),Da=z(),Ea=y("iPad"),Fa=y("iPod");function Ga(){var a=h.document;return a?a.documentMode:void 0}var Ha;
a:{var Ia="",Ja=function(){var a=x;if(ya)return/rv:([^\);]+)(\)|;)/.exec(a);if(xa)return/Edge\/([\d\.]+)/.exec(a);if(B)return/\b(?:MSIE|rv)[: ]([^\);]+)(\)|;)/.exec(a);if(za)return/WebKit\/(\S+)/.exec(a);if(wa)return/(?:Version)[ \/]?(\S+)/.exec(a)}();Ja&&(Ia=Ja?Ja[1]:"");if(B){var Ka=Ga();if(null!=Ka&&Ka>parseFloat(Ia)){Ha=String(Ka);break a}}Ha=Ia}var La=Ha,Ma={},Na;if(h.document&&B){var Oa=Ga();Na=Oa?Oa:parseInt(La,10)||void 0}else Na=void 0;var Pa=Na;var Qa=qa(),Ra=z()||y("iPod"),Sa=y("iPad"),Ta=y("Android")&&!(ra()||qa()||y("Opera")||y("Silk")),Ua=ra(),Va=y("Safari")&&!(ra()||y("Coast")||y("Opera")||y("Edge")||y("Edg/")||y("OPR")||qa()||y("Silk")||y("Android"))&&!(z()||y("iPad")||y("iPod"));function Wa(){}var Xa="function"==typeof Uint8Array;function Ya(a,b,c){a.h=null;b||(b=[]);a.v=void 0;a.o=-1;a.g=b;a:{if(b=a.g.length){--b;var d=a.g[b];if(!(null===d||"object"!=typeof d||Array.isArray(d)||Xa&&d instanceof Uint8Array)){a.s=b-a.o;a.j=d;break a}}a.s=Number.MAX_VALUE}a.l={};if(c)for(b=0;b<c.length;b++)if(d=c[b],d<a.s)d+=a.o,a.g[d]=a.g[d]||Za;else{var e=a.s+a.o;a.g[e]||(a.j=a.g[e]={});a.j[d]=a.j[d]||Za}}var Za=[];
function $a(a,b){if(b<a.s){b+=a.o;var c=a.g[b];return c!==Za?c:a.g[b]=[]}if(a.j)return c=a.j[b],c===Za?a.j[b]=[]:c}function ab(a){a=$a(a,2);return null==a?0:a}function bb(a){a=$a(a,16);a=null==a?a:!!a;return null==a?!1:a}function cb(a,b,c){a.h||(a.h={});if(!a.h[c]){var d=$a(a,c);d&&(a.h[c]=new b(d))}return a.h[c]}function db(a){if(a.h)for(var b in a.h){var c=a.h[b];if(Array.isArray(c))for(var d=0;d<c.length;d++)c[d]&&db(c[d]);else c&&db(c)}return a.g}Wa.prototype.toString=function(){return db(this).toString()};function eb(a){Ya(this,a,fb)}t(eb,Wa);var fb=[17];function gb(a){Ya(this,a,hb)}t(gb,Wa);var hb=[27];function ib(a){Ya(this,a,null)}t(ib,Wa);var jb=document,kb=window;function lb(a,b,c){a.addEventListener&&a.addEventListener(b,c,!1)};function mb(a){return a&&a.parentNode?a.parentNode.removeChild(a):null};function nb(a){var b=a.indexOf("#");0>b&&(b=a.length);var c=a.indexOf("?");if(0>c||c>b){c=b;var d=""}else d=a.substring(c+1,b);return[a.substr(0,c),d,a.substr(b)]}function ob(a,b){return b?a?a+"&"+b:b:a}function pb(a,b){if(!b)return a;a=nb(a);a[1]=ob(a[1],b);return a[0]+(a[1]?"?"+a[1]:"")+a[2]}function qb(a,b,c){if(Array.isArray(b))for(var d=0;d<b.length;d++)qb(a,String(b[d]),c);else null!=b&&c.push(a+(""===b?"":"="+encodeURIComponent(String(b))))}
function rb(a){var b=[],c;for(c in a)qb(c,a[c],b);return b.join("&")}function sb(a,b){b=rb(b);return pb(a,b)}function tb(a){var b=C||{};a=nb(a);var c=a[1],d=[];c&&c.split("&").forEach(function(e){var f=e.indexOf("=");b.hasOwnProperty(0<=f?e.substr(0,f):e)||d.push(e)});a[1]=ob(d.join("&"),rb(b));return a[0]+(a[1]?"?"+a[1]:"")+a[2]};function ub(){var a=vb;try{return!!a&&null!=a.location.href&&va(a,"foo")}catch(b){return!1}};function wb(a,b=null){xb(a,b)}function xb(a,b){var c=window;c.google_image_requests||(c.google_image_requests=[]);const d=c.document.createElement("img");if(b){const e=f=>{b&&b(f);d.removeEventListener&&d.removeEventListener("load",e,!1);d.removeEventListener&&d.removeEventListener("error",e,!1)};lb(d,"load",e);lb(d,"error",e)}d.src=a;c.google_image_requests.push(d)};function yb(a){a&&"function"==typeof a.$&&a.$()};function D(){this.s=this.s;this.o=this.o}D.prototype.s=!1;D.prototype.$=function(){this.s||(this.s=!0,this.h())};D.prototype.h=function(){if(this.o)for(;this.o.length;)this.o.shift()()};var zb={};function Ab(){if(zb!==zb)throw Error("Bad secret");};function Bb(){var a="undefined"!==typeof window?window.trustedTypes:void 0;return null!==a&&void 0!==a?a:null};var Cb,Db=class{};class Eb extends Db{constructor(){var a=null!==Fb&&void 0!==Fb?Fb:"";super();Ab();this.g=a}toString(){return this.g.toString()}}var Fb=null===(Cb=Bb())||void 0===Cb?void 0:Cb.emptyHTML;new Eb;var Gb,Hb=class{};class Ib extends Hb{constructor(){var a=null!==Jb&&void 0!==Jb?Jb:"";super();Ab();this.g=a}toString(){return this.g.toString()}}var Jb=null===(Gb=Bb())||void 0===Gb?void 0:Gb.emptyScript;new Ib;var Kb=class{};class Lb extends Kb{constructor(a){super();Ab();this.g=a}toString(){return this.g}}new Lb("about:blank");var Mb=new Lb("about:invalid#zTSz");const Nb="DATA HTTP HTTPS MAILTO FTP RELATIVE".split(" ");function Ob(a,b=Nb){var c;var d=a.substring(0,14).indexOf(":");d=null!==(c=Pb[0>d?"":a.substr(0,d).toLowerCase()])&&void 0!==c?c:Qb;if(b.includes(d.scheme)&&d.A(a))return new Lb(a)}function Rb(a,b=Nb){return Ob(a,b)||Mb}
const Qb={scheme:"RELATIVE",A:a=>/^[^:/?#]*(?:[/?#]|$)/i.test(a)},Pb={tel:{scheme:"TEL",A:E("tel:")},callto:{scheme:"CALLTO",A:a=>/^callto:\+?\d*$/i.test(a)},ssh:{scheme:"SSH",A:E("ssh://")},rtsp:{scheme:"RTSP",A:E("rtsp://")},data:{scheme:"DATA",A:a=>{{const b=a.match(/^data:(.*);base64,[a-z0-9+\/]+=*$/i);if(a=2===(null===b||void 0===b?void 0:b.length))a=b[1].match(/^([^;]+)(?:;\w+=(?:\w+|"[\w;,= ]+"))*$/i),a=2===(null===a||void 0===a?void 0:a.length)&&(/^image\/(?:bmp|gif|jpeg|jpg|png|tiff|webp|x-icon)$/i.test(a[1])||
/^video\/(?:mpeg|mp4|ogg|webm|x-matroska)$/i.test(a[1])||/^audio\/(?:3gpp2|3gpp|aac|L16|midi|mp3|mp4|mpeg|oga|ogg|opus|x-m4a|x-matroska|x-wav|wav|webm)$/i.test(a[1]))}return a}},http:{scheme:"HTTP",A:E("http:")},https:{scheme:"HTTPS",A:E("https:")},ftp:{scheme:"FTP",A:E("ftp:")},mailto:{scheme:"MAILTO",A:E("mailto:")},intent:{scheme:"INTENT",A:E("intent:")},market:{scheme:"MARKET",A:E("market:")},itms:{scheme:"ITMS",A:E("itms:")},"itms-appss":{scheme:"ITMS_APPSS",A:E("itms-appss:")},"itms-services":{scheme:"ITMS_SERVICES",
A:E("itms-services:")}};function E(a){return b=>b.substr(0,a.length).toLowerCase()===a};function Sb(a,b){if(a instanceof w)return a;const c=Rb(a,void 0);c===Mb&&b(a);if(c instanceof Lb)a=c.g;else throw Error("wrong type");return new w(a,la)}var Tb=a=>{var b=`${"http:"===kb.location.protocol?"http:":"https:"}//${"pagead2.googlesyndication.com"}/pagead/gen_204`;return c=>{c=sb(b,{id:"unsafeurl",ctx:a,url:c});navigator.sendBeacon&&navigator.sendBeacon(c,"")}};var Ub=!!window.google_async_iframe_id;let vb=Ub&&window.parent||window;let Vb=null;class Wb{constructor(a,b){var c=(c=h.performance)&&c.now?c.now():null;c||(c=(c=h.performance)&&c.now&&c.timing?Math.floor(c.now()+c.timing.navigationStart):Date.now());this.label=a;this.type=b;this.value=c;this.duration=0;this.uniqueId=Math.random();this.slotId=void 0}};const F=h.performance,Xb=!!(F&&F.mark&&F.measure&&F.clearMarks),Yb=function(a){let b=!1,c;return function(){b||(c=a(),b=!0);return c}}(()=>{var a;if(a=Xb){var b;if(null===Vb){Vb="";try{a="";try{a=h.top.location.hash}catch(c){a=h.location.hash}a&&(Vb=(b=a.match(/\bdeid=([\d,]+)/))?b[1]:"")}catch(c){}}b=Vb;a=!!b.indexOf&&0<=b.indexOf("1337")}return a});function Zb(a){a&&F&&Yb()&&(F.clearMarks(`goog_${a.label}_${a.uniqueId}_start`),F.clearMarks(`goog_${a.label}_${a.uniqueId}_end`))}
class $b{constructor(){var a=G;this.g=[];this.j=a||h;let b=null;a&&(a.google_js_reporting_queue=a.google_js_reporting_queue||[],this.g=a.google_js_reporting_queue,b=a.google_measure_js_timing);this.h=Yb()||(null!=b?b:1>Math.random())}start(a,b){if(!this.h)return null;a=new Wb(a,b);b=`goog_${a.label}_${a.uniqueId}_start`;F&&Yb()&&F.mark(b);return a}};if(Ub&&!ub()){let a="."+jb.domain;try{for(;2<a.split(".").length&&!ub();)jb.domain=a=a.substr(a.indexOf(".")+1),vb=window.parent}catch(b){}ub()||(vb=window)}const G=vb,H=new $b;var ac=()=>{G.google_measure_js_timing||(H.h=!1,H.g!=H.j.google_js_reporting_queue&&(Yb()&&Array.prototype.forEach.call(H.g,Zb,void 0),H.g.length=0))};"number"!==typeof G.google_srt&&(G.google_srt=Math.random());"complete"==G.document.readyState?ac():H.h&&lb(G,"load",()=>{ac()});const bc=class{constructor(){this.g=new XMLHttpRequest}get(a,b){if(this.g&&(0==this.g.readyState||4==this.g.readyState))try{this.g.onreadystatechange=r(this.h,this,b),this.g.open("GET",a,!0),this.g.send(null)}catch(c){b()}}h(a){4==this.g.readyState&&a()}};function cc(a){a.v||(a.o||a.h?a.j||dc(a):(a.j&&(a.j=!1,window.clearTimeout(a.G),a.G=void 0),dc(a)))}
function dc(a){if(!a.v){a.v=!0;a.F=!0;var b=0==a.B?0:a.B-a.O,c=0==a.C?0:a.C-a.W,d=0==a.N?0:a.N-a.Z,e=a.s&&a.s.g?a.s.g.status:"noreq",f=a.g?a.g.status:"noreq",g=/&ctype=\d+/.exec(a.D);g=g?g[0]:"";a.Y++;a.P=["//pagead2.googlesyndication.com/pagead/gen_204?id=ctc_metrics",g,"&dc="+a.S,"&ec=0","&rc="+a.Y,"&ct=0","&ctc_num="+a.M,"&ctc_gvn="+a.l,"&ctc_cs_time="+b,"&ctc_gv_time="+c,"&ctc_to_time="+d,"&ctc_cs_status="+e,"&ctc_gv_status="+f].join("");(new bc).get(a.P,r(a.X,a));window.setTimeout(r(a.X,a),2E3)}}
function ec(a){const b=()=>{a.g&&4==a.g.readyState&&(a.h=!1,200==a.g.status&&a.g.responseText&&0<a.g.responseText.length&&(a.l="tel:"+a.g.responseText))};a.h||null!=a.l||(a.h=!0,a.g=new XMLHttpRequest,a.g.onreadystatechange=b,a.g.open("GET",a.R,!0),a.g.send(null));a.o||null!=a.s||(a.o=!0,a.s=new bc,a.s.get(a.D,()=>{a.o=!1}));a.j||(null==a.l?(a.j=!0,window.setTimeout(r(a.J,a),a.U)):a.J())}
var fc=class{constructor(a,b,c,d,e=0){this.D=a;this.R=b;this.P=null;this.M=c;this.T=d;this.j=this.F=this.v=this.h=this.o=!1;this.G=void 0;this.g=this.s=this.l=null;this.S=this.ba=this.Y=this.C=this.B=this.N=this.W=this.O=this.Z=0;this.U=e}aa(){this.B=Date.now();this.o=!1;cc(this)}V(){try{this.g&&4==this.g.readyState&&this.h&&(this.C=Date.now(),this.h=!1,this.g.responseText&&0<this.g.responseText.length&&(this.l="tel:"+this.g.responseText))}finally{cc(this)}}ca(){this.N=Date.now();this.j=!1;cc(this)}J(){this.j=
this.h=this.o=!1;null!=this.T?this.T(this.l||this.M):sa(window.top.location,Sb(ma(this.l||this.M),Tb(607)))}X(){this.F&&(this.F=!1,this.J())}};k("ctc_bd",function(a,b,c,d=!1){c=c||function(){sa(window.top.location,Sb(ma(b),Tb(606)))};var e=new bc;d?(e.get(a,l),setTimeout(c,0)):e.get(a,c)},void 0);k("init_gvc",function(a,b,c,d,e=0){return new fc(a,b,c,d,e)},void 0);
k("ctc_bd_gv",function(a){if(0<a.U)ec(a);else{var b=Date.now();a.o||a.h||a.j?a.S++:a.ba=b;var c=!1,d=!1,e=!1;a.o||(a.o=!0,a.v=!1,a.O=b,a.B=b,d=!0);a.h||null!=a.l||(a.h=!0,a.v=!1,a.W=b,a.C=b,e=!0);a.j||(a.j=!0,a.v=!1,a.Z=b,c=!0);c&&(a.G=window.setTimeout(r(a.ca,a),2E3));d&&(a.s=new bc,a.s.get(a.D,r(a.aa,a)));if(e)try{a.g=new XMLHttpRequest,a.g.onreadystatechange=r(a.V,a),a.g.open("GET",a.R,!0),a.g.send(null)}catch(f){a.V()}}},void 0);var gc,hc,ic,jc;function kc(){return h.navigator?h.navigator.userAgent:""}function I(a){return-1!=kc().indexOf(a)}var lc=I("(iPad")||I("(Macintosh")||I("(iPod")||I("(iPhone"),mc=I("Android"),nc=I("MSIE")||I("IEMobile")||I("Windows Phone");function J(){void 0===ic&&(ic=I("afma-sdk-a")?!0:!1);return ic}function oc(a){var b;void 0===jc&&(jc=J()?(b=kc().match(/afma\-sdk\-a\-v\.?([\d+\.]+)/))?b[1]:"":"");return(b=jc)?0<=ja(b,a):!1};function K(a,b){this.type=a;this.g=this.target=b;this.defaultPrevented=!1}K.prototype.h=function(){this.defaultPrevented=!0};function L(a,b){this.messageName=a;this.parameters=b||{}}function pc(a,b){K.call(this,a.messageName,b);this.params=a.parameters||{}}t(pc,K);var qc;(qc=!B)||(qc=9<=Number(Pa));var rc=qc,sc;if(sc=B)sc=!(Object.prototype.hasOwnProperty.call(Ma,"9")?Ma["9"]:Ma["9"]=0<=ja(La,"9"));var tc=sc,uc=function(){if(!h.addEventListener||!Object.defineProperty)return!1;var a=!1,b=Object.defineProperty({},"passive",{get:function(){a=!0}});try{h.addEventListener("test",l,b),h.removeEventListener("test",l,b)}catch(c){}return a}();function M(a,b){K.call(this,a?a.type:"");this.relatedTarget=this.g=this.target=null;this.button=this.screenY=this.screenX=this.clientY=this.clientX=0;this.key="";this.metaKey=this.shiftKey=this.altKey=this.ctrlKey=!1;this.pointerId=0;this.pointerType="";this.j=null;a&&this.init(a,b)}t(M,K);var vc={2:"touch",3:"pen",4:"mouse"};
M.prototype.init=function(a,b){var c=this.type=a.type,d=a.changedTouches&&a.changedTouches.length?a.changedTouches[0]:null;this.target=a.target||a.srcElement;this.g=b;(b=a.relatedTarget)?ya&&(va(b,"nodeName")||(b=null)):"mouseover"==c?b=a.fromElement:"mouseout"==c&&(b=a.toElement);this.relatedTarget=b;d?(this.clientX=void 0!==d.clientX?d.clientX:d.pageX,this.clientY=void 0!==d.clientY?d.clientY:d.pageY,this.screenX=d.screenX||0,this.screenY=d.screenY||0):(this.clientX=void 0!==a.clientX?a.clientX:
a.pageX,this.clientY=void 0!==a.clientY?a.clientY:a.pageY,this.screenX=a.screenX||0,this.screenY=a.screenY||0);this.button=a.button;this.key=a.key||"";this.ctrlKey=a.ctrlKey;this.altKey=a.altKey;this.shiftKey=a.shiftKey;this.metaKey=a.metaKey;this.pointerId=a.pointerId||0;this.pointerType="string"===typeof a.pointerType?a.pointerType:vc[a.pointerType]||"";this.j=a;a.defaultPrevented&&M.I.h.call(this)};
M.prototype.h=function(){M.I.h.call(this);var a=this.j;if(a.preventDefault)a.preventDefault();else if(a.returnValue=!1,tc)try{if(a.ctrlKey||112<=a.keyCode&&123>=a.keyCode)a.keyCode=-1}catch(b){}};var N="closure_listenable_"+(1E6*Math.random()|0);var wc=0;function xc(a,b,c,d,e){this.listener=a;this.g=null;this.src=b;this.type=c;this.capture=!!d;this.L=e;this.key=++wc;this.H=this.K=!1}function yc(a){a.H=!0;a.listener=null;a.g=null;a.src=null;a.L=null};function zc(a){this.src=a;this.g={};this.h=0}zc.prototype.add=function(a,b,c,d,e){var f=a.toString();a=this.g[f];a||(a=this.g[f]=[],this.h++);var g=Ac(a,b,d,e);-1<g?(b=a[g],c||(b.K=!1)):(b=new xc(b,this.src,f,!!d,e),b.K=c,a.push(b));return b};function Bc(a,b,c,d,e){b=b.toString();if(b in a.g){var f=a.g[b];c=Ac(f,c,d,e);-1<c&&(yc(f[c]),Array.prototype.splice.call(f,c,1),0==f.length&&(delete a.g[b],a.h--))}}
function Cc(a,b){var c=b.type;if(c in a.g){var d=a.g[c];var e=Array.prototype.indexOf.call(d,b,void 0);var f;(f=0<=e)&&Array.prototype.splice.call(d,e,1);f&&(yc(b),0==a.g[c].length&&(delete a.g[c],a.h--))}}function Ac(a,b,c,d){for(var e=0;e<a.length;++e){var f=a[e];if(!f.H&&f.listener==b&&f.capture==!!c&&f.L==d)return e}return-1};var Dc="closure_lm_"+(1E6*Math.random()|0),Ec={},Fc=0;function Gc(a,b,c,d,e){if(d&&d.once)return O(a,b,c,d,e);if(Array.isArray(b)){for(var f=0;f<b.length;f++)Gc(a,b[f],c,d,e);return null}c=Hc(c);return a&&a[N]?a.g.add(String(b),c,!1,q(d)?!!d.capture:!!d,e):Ic(a,b,c,!1,d,e)}
function Ic(a,b,c,d,e,f){if(!b)throw Error("Invalid event type");var g=q(e)?!!e.capture:!!e,n=Jc(a);n||(a[Dc]=n=new zc(a));c=n.add(b,c,d,g,f);if(c.g)return c;d=Kc();c.g=d;d.src=a;d.listener=c;if(a.addEventListener)uc||(e=g),void 0===e&&(e=!1),a.addEventListener(b.toString(),d,e);else if(a.attachEvent)a.attachEvent(Lc(b.toString()),d);else if(a.addListener&&a.removeListener)a.addListener(d);else throw Error("addEventListener and attachEvent are unavailable.");Fc++;return c}
function Kc(){var a=Mc,b=rc?function(c){return a.call(b.src,b.listener,c)}:function(c){c=a.call(b.src,b.listener,c);if(!c)return c};return b}function O(a,b,c,d,e){if(Array.isArray(b)){for(var f=0;f<b.length;f++)O(a,b[f],c,d,e);return null}c=Hc(c);return a&&a[N]?a.g.add(String(b),c,!0,q(d)?!!d.capture:!!d,e):Ic(a,b,c,!0,d,e)}
function Nc(a,b,c,d,e){if(Array.isArray(b))for(var f=0;f<b.length;f++)Nc(a,b[f],c,d,e);else(d=q(d)?!!d.capture:!!d,c=Hc(c),a&&a[N])?Bc(a.g,String(b),c,d,e):a&&(a=Jc(a))&&(b=a.g[b.toString()],a=-1,b&&(a=Ac(b,c,d,e)),(c=-1<a?b[a]:null)&&Oc(c))}
function Oc(a){if("number"!==typeof a&&a&&!a.H){var b=a.src;if(b&&b[N])Cc(b.g,a);else{var c=a.type,d=a.g;b.removeEventListener?b.removeEventListener(c,d,a.capture):b.detachEvent?b.detachEvent(Lc(c),d):b.addListener&&b.removeListener&&b.removeListener(d);Fc--;(c=Jc(b))?(Cc(c,a),0==c.h&&(c.src=null,b[Dc]=null)):yc(a)}}}function Lc(a){return a in Ec?Ec[a]:Ec[a]="on"+a}
function Pc(a,b,c,d){var e=!0;if(a=Jc(a))if(b=a.g[b.toString()])for(b=b.concat(),a=0;a<b.length;a++){var f=b[a];f&&f.capture==c&&!f.H&&(f=Qc(f,d),e=e&&!1!==f)}return e}function Qc(a,b){var c=a.listener,d=a.L||a.src;a.K&&Oc(a);return c.call(d,b)}
function Mc(a,b){if(a.H)return!0;if(!rc){if(!b)a:{b=["window","event"];for(var c=h,d=0;d<b.length;d++)if(c=c[b[d]],null==c){b=null;break a}b=c}d=b;b=new M(d,this);c=!0;if(!(0>d.keyCode||void 0!=d.returnValue)){a:{var e=!1;if(0==d.keyCode)try{d.keyCode=-1;break a}catch(g){e=!0}if(e||void 0==d.returnValue)d.returnValue=!0}d=[];for(e=b.g;e;e=e.parentNode)d.push(e);a=a.type;for(e=d.length-1;0<=e;e--){b.g=d[e];var f=Pc(d[e],a,!0,b);c=c&&f}for(e=0;e<d.length;e++)b.g=d[e],f=Pc(d[e],a,!1,b),c=c&&f}return c}return Qc(a,
new M(b,this))}function Jc(a){a=a[Dc];return a instanceof zc?a:null}var Rc="__closure_events_fn_"+(1E9*Math.random()>>>0);function Hc(a){if("function"===typeof a)return a;a[Rc]||(a[Rc]=function(b){return a.handleEvent(b)});return a[Rc]};function P(a){D.call(this);this.j=a;this.g={}}t(P,D);var Sc=[];function Tc(a){ea(a.g,function(b,c){this.g.hasOwnProperty(c)&&Oc(b)},a);a.g={}}P.prototype.h=function(){P.I.h.call(this);Tc(this)};P.prototype.handleEvent=function(){throw Error("EventHandler.handleEvent not implemented");};function Q(){D.call(this);this.g=new zc(this);this.G=this;this.C=null}t(Q,D);Q.prototype[N]=!0;Q.prototype.addEventListener=function(a,b,c,d){Gc(this,a,b,c,d)};Q.prototype.removeEventListener=function(a,b,c,d){Nc(this,a,b,c,d)};
function Uc(a,b){var c,d=a.C;if(d)for(c=[];d;d=d.C)c.push(d);a=a.G;d=b.type||b;if("string"===typeof b)b=new K(b,a);else if(b instanceof K)b.target=b.target||a;else{var e=b;b=new K(d,a);ha(b,e)}e=!0;if(c)for(var f=c.length-1;0<=f;f--){var g=b.g=c[f];e=Vc(g,d,!0,b)&&e}g=b.g=a;e=Vc(g,d,!0,b)&&e;e=Vc(g,d,!1,b)&&e;if(c)for(f=0;f<c.length;f++)g=b.g=c[f],e=Vc(g,d,!1,b)&&e}
Q.prototype.h=function(){Q.I.h.call(this);if(this.g){var a=this.g,b=0,c;for(c in a.g){for(var d=a.g[c],e=0;e<d.length;e++)++b,yc(d[e]);delete a.g[c];a.h--}}this.C=null};function Vc(a,b,c,d){b=a.g.g[String(b)];if(!b)return!0;b=b.concat();for(var e=!0,f=0;f<b.length;++f){var g=b[f];if(g&&!g.H&&g.capture==c){var n=g.listener,u=g.L||g.src;g.K&&Cc(a.g,g);e=!1!==n.call(u,d)&&e}}return e&&!d.defaultPrevented};function R(a,b){Q.call(this);this.B=a||1;this.v=b||h;this.D=r(this.J,this);this.F=Date.now()}t(R,Q);R.prototype.l=!1;R.prototype.j=null;R.prototype.J=function(){if(this.l){var a=Date.now()-this.F;0<a&&a<.8*this.B?this.j=this.v.setTimeout(this.D,this.B-a):(this.j&&(this.v.clearTimeout(this.j),this.j=null),Uc(this,"tick"),this.l&&(Wc(this),this.start()))}};R.prototype.start=function(){this.l=!0;this.j||(this.j=this.v.setTimeout(this.D,this.B),this.F=Date.now())};
function Wc(a){a.l=!1;a.j&&(a.v.clearTimeout(a.j),a.j=null)}R.prototype.h=function(){R.I.h.call(this);Wc(this);delete this.v};function Xc(){if(window.googleJsEnvironment&&("rhino"==window.googleJsEnvironment.environment||"jscore"==window.googleJsEnvironment.environment))return new Yc;if(nc&&window.external&&"notify"in window.external)return new Zc;if(mc&&window.googleAdsJsInterface&&"notify"in window.googleAdsJsInterface)try{return window.googleAdsJsInterface.notify("gmsg://mobileads.google.com/noop"),new Yc}catch(a){}else if(window.webkit&&window.webkit.messageHandlers&&window.webkit.messageHandlers.gadGMSGHandler)return new $c;
return new S}function ad(){bd||(bd=Xc());return bd}var bd=null;function T(){}t(T,D);function cd(a){var b="gmsg://mobileads.google.com/"+a.messageName;a=v(a.parameters);a["google.afma.Notify_dt"]=(new Date).getTime();{const c={};for(const d in a){const e=encodeURIComponent(String(d));c[e]=a[d]}b=sb(b,c)}return b}
function U(a,b){this.B=a;this.C=b||1;this.v=[];this.l=new R(this.C);a=this.D=new P(this);b=this.l;var c=this.F,d="tick";Array.isArray(d)||(d&&(Sc[0]=d.toString()),d=Sc);for(var e=0;e<d.length;e++){var f=Gc(b,d[e],c||a.handleEvent,!1,a.j||a);if(!f)break;a.g[f.key]=f}}t(U,T);U.prototype.sendMessage=function(a){this.v.push(a);this.l.l||(a=this.v.shift(),this.B(a),this.l.start())};U.prototype.F=function(){const a=this.v.shift();a?this.B(a):Wc(this.l)};function Zc(){}t(Zc,T);
Zc.prototype.sendMessage=function(a){a=cd(a);window.external.notify(a)};function S(){U.call(this,this.G);this.g=[];this.j=0}t(S,U);S.prototype.G=function(a){var b=this.g[this.j];if(!b){var c=document;b="IFRAME";"application/xhtml+xml"===c.contentType&&(b=b.toLowerCase());b=c.createElement(b);b.id="afma-notify-"+(new Date).getTime();b.style.display="none";this.g[this.j]=b}this.j=(this.j+1)%25;a=cd(a);b.src=a;b.parentNode||document.body.appendChild(b)};
S.prototype.h=function(){this.g.forEach(mb);this.g=[];S.I.h.call(this)};function Yc(){}t(Yc,T);Yc.prototype.sendMessage=function(a){a=cd(a);window.googleAdsJsInterface&&window.googleAdsJsInterface.notify&&(window.googleAdsJsInterface.notify(a),window.googleAdsJsInterface.DEBUG&&console.log(a))};function $c(){}t($c,T);$c.prototype.sendMessage=function(a){a=cd(a);window.webkit&&window.webkit.messageHandlers&&window.webkit.messageHandlers.gadGMSGHandler&&window.webkit.messageHandlers.gadGMSGHandler.postMessage(a)};function dd(a,{data:b,source:c}){if(c&&b){var d=a.j;if("arwebview_iframe_loaded"===b&&a.h)k("JavascriptWebViewBridge.incoming.postMessage",a.s.bind(a),h),-1===d.indexOf(c)&&d.push(c);else{var e=b.messageName;b=b.parameters;if(a.h)switch(e){case "mraid_loaded":!1===b.is_top_win&&(a.o=!0,h.AFMA_updateActiveView||k("AFMA_updateActiveView",a.l.bind(a),h),-1===d.indexOf(c)&&(d.push(c),"undefined"!==typeof c.postMessage&&c.postMessage(new L("mraid_env_obj",window.MRAID_ENV),"*")));break;case "start_tracking_action":0==
a.g&&window.AFMA_SendMessage("trackActiveViewUnit");a.g+=1;break;case "stop_tracking_action":--a.g,0==a.g&&(window.AFMA_SendMessage("untrackActiveViewUnit",{hashCode:b.hashCode}),window.AFMA_updateActiveView=da)}else switch(e){case "mraid_env_obj":window.MRAID_ENV=b;break;case "update_activeview_action":window.AFMA_updateActiveView(b);break;case "receive_message_action":window.AFMA_ReceiveMessage(b.messageName,b.parameters)}}}}function ed(a,b){a.j.forEach(c=>c.postMessage(b,"*"))}
class fd{constructor(){this.j=[];this.h=window===window.top;this.o=!1;this.g=0;"undefined"!==typeof window.addEventListener&&window.addEventListener("message",a=>dd(this,a))}l(a){this.h&&ed(this,new L("update_activeview_action",a))}s(a){this.h&&ed(this,{name:"arwebview_message_forwarded",message:a})}};function V(){Q.call(this);this.l=ad();this.l=ad();var a=ca(yb,this.l);this.s?a():(this.o||(this.o=[]),this.o.push(a));this.j={};this.v=new fd}t(V,Q);V.prototype.sendMessage=function(a,b){let c;"string"===typeof a?c=new L(a,b):a instanceof L&&(c=a);"loading"==document.readyState?(a=r(this.l.sendMessage,this.l,c),O(h,"DOMContentLoaded",a,!1,this)):this.l.sendMessage(c)};
V.prototype.receiveMessage=function(a,b){if(this.shouldForwardMessageToIframe())this.forwardMessage(new L("receive_message_action",new L(a,b)));else{const c=document.getElementById("ad_iframe");void 0!=c&&void 0!=c.contentWindow&&void 0!=c.contentWindow.AFMA_ReceiveMessage&&c.contentWindow.AFMA_ReceiveMessage(a,b)}"onshow"==a&&"loading"==document.readyState?(a=r(gd,h,a,b),O(h,"DOMContentLoaded",a)):Uc(this,new pc(new L(a,b),this))};
V.prototype.addObserver=function(a,b,c){c=r(c,b);const d=r(function(e){c(e.type,e.params)},b);this.g.add(String(a),d,!1,void 0,void 0);this.j[a]||(this.j[a]={});this.j[a][b]=d};V.prototype.removeObserver=function(a,b){this.j[a]&&this.j[a][b]&&(Bc(this.g,String(a),this.j[a][b],void 0,void 0),delete this.j[a][b])};V.prototype.shouldForwardMessageToIframe=function(){return this.v.o};V.prototype.forwardMessage=function(a){ed(this.v,a)};
function X(a,b){h.AFMA_Communicator?h.AFMA_Communicator.sendMessage(a,b):hd(a,b)}function hd(a,b){"loading"==document.readyState?(a=r(hd,null,a,b),O(h,"DOMContentLoaded",a,!1)):(a=new L(a,b),ad().sendMessage(a))}function gd(a,b){h.AFMA_Communicator.receiveMessage(a,b)}function id(a,b,c,d){h.AFMA_Communicator.removeEventListener(a,b,c,d)}function Y(a,b,c,d){h.AFMA_Communicator.addEventListener(a,b,c,d)}function jd(a,b,c){h.AFMA_Communicator.addObserver(a,b,c)}
function kd(a,b){h.AFMA_Communicator.removeObserver(a,b)}h.AFMA_Communicator||(k("AFMA_AddEventListener",Y,h),k("AFMA_RemoveEventListener",id,h),k("AFMA_AddObserver",jd,h),k("AFMA_RemoveObserver",kd,h),k("AFMA_ReceiveMessage",gd,h),k("AFMA_SendMessage",X,h),h.AFMA_Communicator=new V);k("google.afma.support.blockPageClosed",function(){X("delayPageClosed",{start:1})},void 0);k("google.afma.support.unblockPageClosed",function(){X("delayPageClosed",{stop:1})},void 0);k("google.afma.support.blockPageLoaded",function(){X("delayPageLoaded",{start:1})},void 0);function ld(){X("delayPageLoaded",{stop:1})}k("google.afma.support.unblockPageLoaded",ld,void 0);k("google.afma.support.cancelPageLoaded",function(){J()&&!oc("9047000.0.0")?ld():X("delayPageLoaded",{cancel:1})},void 0);
k("google.afma.support.disableBackButton",function(a){X("backButton",{disabled:a})},void 0);k("google.afma.support.notifyRewardedVideoStart",function(){X("reward",{action:"video_start"})},void 0);k("google.afma.support.notifyRewardedVideoComplete",function(){X("reward",{action:"video_complete"})},void 0);k("google.afma.support.grantReward",function(a){const b={action:"grant"};a?(b.amount=a.amount,b.type=a.type):b.amount=0;X("reward",b)},void 0);
function md(a){if(a&&0==a.lastIndexOf("intent:",0)){var b=a.indexOf("#Intent;");if(!(0>b)){var c={id:a,url:a.substr(9,b-9)};a=a.substr(b+8).split(";");b="";for(let d=0;d<a.length;d++){const e=a[d].split("=");if(2==e.length)switch(e[0]){case "package":c.packageName=e[1];break;case "action":c.action=e[1];break;case "scheme":b=e[1]}}b&&(c.url=b+"://"+c.url);return c}}}
function nd(){var a;lc?(void 0===hc&&(hc=(a=/CPU\s+(?:(?:i?OS)|(?:iPhone)|(?:iPhone\s+OS))\s+([0-9_|\.]+)/.exec(kc()))&&2==a.length?a[1].replace(/_/g,"."):I("(Macintosh")?"13.0":""),a=0<=ja(hc,9)):a=!1;return a}
k("google.afma.support.canOpenURLs",function(a,b,c,d){const e=c||function(){};c=d||500;let f;f=a instanceof Array?a:[a];if(nd()){a={};for(c=0;c<f.length;++c)a[f[c]]=!0;b("openableURLs",a)}else{a=f.join(",");var g=!1,n=function(u){id("openableURLs",n);if(!g){g=!0;var A=v(u.params);for(let p=0;p<f.length;++p){const W=f[p];var m=decodeURIComponent(W.replace(/\+/g," "));m=A[m];null!=m&&(A[W]=m)}b(u.type,A)}};Y("openableURLs",n);X("canOpenURLs",{urls:a});setTimeout(function(){g||(g=!0,e())},c)}},void 0);
k("google.afma.support.canOpenAndroidApp",function(a,b,c=function(){},d=500){function e(g){id("openableApp",e);if(!f){f=!0;var n=v(g.params);b(g.type,n)}}if(!J())return!1;let f=!1;Y("openableApp",e);X("canOpenApp",{package_name:a});setTimeout(function(){f||(f=!0,c())},d);return!0},void 0);
function od(a,b,c,d){function e(A){id("openableIntents",e);if(!g){g=!0;var m=v(A.params),p={};for(const W in m)p[n[W]]=m[W];b(A.type,p)}}if(!J())return!1;const f=c||function(){};c=d||500;let g=!1;const n={};d=[];for(let A=0;A<a.length;++A){const m=a[A];var u=ta(m.id).toString();n[u]=m.id;const p={};p.id=u;m.url&&(p.u=m.url);m.url&&(0==m.url.lastIndexOf("intent:",0)||0==m.url.lastIndexOf("Intent#",0))&&(p.intent_url=m.url,delete p.u,u=md(m.url))&&(u.url&&(p.u=u.url),u.packageName&&(p.p=u.packageName),
u.action&&(p.i=u.action));m.mimeType&&(p.m=m.mimeType);m.packageName&&(p.p=m.packageName);m.action&&(p.i=m.action);d.push(p)}a={intents:d};Y("openableIntents",e);X("canOpenIntents",{data:JSON.stringify(a)});setTimeout(function(){g||(g=!0,f())},c);return!0}k("google.afma.support.canOpenIntents",od,void 0);
k("google.afma.support.canOpenIntentsForAndroid",function(a,b,c,d){if(!J())return!1;var e;if(e=J())void 0===gc&&(gc=(e=/Android\s+([0-9.]+)/.exec(kc()))&&2==e.length?e[1]:""),e=(e=gc)?0<=ja(e,"11.0.0"):!1;if(!e||!oc(204204100))return od(a,b,c,d);a=a instanceof Array?a:[a];c={};for(d=0;d<a.length;++d)c[a[d].id]=!0;b("openableIntents",c);return!0},void 0);k("google.afma.support.trackActiveViewUnit",function(){X("trackActiveViewUnit")},void 0);
k("google.afma.support.untrackActiveViewUnit",function(){X("untrackActiveViewUnit")},void 0);k("google.afma.support.sendInstrumentGmsg",function(a){X("instrument",a)},void 0);Y("onshow",function(){});Y("onhide",function(){});(function(){if(Ba){var a=/Windows NT ([0-9.]+)/;return(a=a.exec(x))?a[1]:"0"}return Aa?(a=/1[0|1][_.][0-9_.]+/,(a=a.exec(x))?a[0].replace(/_/g,"."):"10"):Ca?(a=/Android\s+([^\);]+)(\)|;)/,(a=a.exec(x))?a[1]:""):Da||Ea||Fa?(a=/(?:iPhone|CPU)\s+OS\s+(\S+)/,(a=a.exec(x))?a[1].replace(/_/g,"."):""):""})();function Z(a){return(a=a.exec(x))?a[1]:""}(function(){if(Qa)return Z(/Firefox\/([0-9.]+)/);if(B||xa||wa)return La;if(Ua)return z()||y("iPad")||y("iPod")?Z(/CriOS\/([0-9.]+)/):Z(/Chrome\/([0-9.]+)/);if(Va&&!(z()||y("iPad")||y("iPod")))return Z(/Version\/([0-9.]+)/);if(Ra||Sa){var a=/Version\/(\S+).*Mobile\/(\S+)/.exec(x);if(a)return a[1]+"."+a[2]}else if(Ta)return(a=Z(/Android\s+([0-9.]+)/))?a:Z(/Version\/([0-9.]+)/);return""})();var C={};
function pd(a){a.stopPropagation();a.preventDefault();C.clo_n=(C.clo_n||0)+1;a=Date.now()-C.clo_e_t;1==C.clo_n&&(C.clo_t=a);C.clo_t_n=a;a=Math.floor(2147483648*Math.random()).toString(36)+Math.abs(Math.floor(2147483648*Math.random())^Date.now()).toString(36);a=null!=a?"="+encodeURIComponent(String(a)):"";a=pb("https://pagead2.googlesyndication.com/pagead/gen_204","zx"+a);a=tb(a);try{window.googleJsEnvironment&&window.googleJsEnvironment.pinger&&window.googleJsEnvironment.pinger.pingUrl?window.googleJsEnvironment.pinger.pingUrl(a):wb(a,
void 0)}catch(b){}X("close",void 0)};var qd=class{constructor(){}j(){}h(){}};function rd(){window.oneAfmaInstance&&(window.oneAfmaInstance.useCustomClose(!0),sd(()=>void window.oneAfmaInstance.useCustomClose(!0)))}function td(){window.oneAfmaInstance&&(window.oneAfmaInstance.useCustomClose(!1),sd(()=>void window.oneAfmaInstance.useCustomClose(!1)))}function sd(a){window.AFMA_Communicator&&window.AFMA_Communicator.addEventListener("onshow",a)};function ud(a,b){a=a.getElementsByTagName("META");for(let c=0;c<a.length;++c)if(a[c].getAttribute("name")===b)return a[c].getAttribute("content")||"";return""};function vd(a,b,c){a.body.addEventListener(b,c)}
var wd=class{constructor(a){this.body=a;var b=ud(a,"namespace");if(!b){b="ns-"+Math.random().toString(36).substr(2,5);a:{var c=a.getElementsByTagName("META");for(let d=0;d<c.length;++d)if("namespace"===c[d].getAttribute("name")&&c[d].getAttribute("index")===(0).toString()){c[d].setAttribute("content",b);break a}c=a.querySelector("#mys-meta");c||(c=document.createElement("div"),c.id="mys-meta",c.style.position="absolute",c.style.display="none",a.appendChild(c));a=document.createElement("META");a.setAttribute("name",
"namespace");a.setAttribute("content",b);a.setAttribute("index",(0).toString());c.appendChild(a)}}}};class xd{constructor(){this.g={}}set(a,b){this.g[a]=b}get(a){return this.g[a]}};var yd=class{constructor(){this.g=!(!window.mys||!window.mys.pingback)}setAttribute(a,b){this.g&&window.mys.pingback.setAttribute(a,b)}setData(a,b){this.g&&window.mys.pingback.setData(a,b,1)}send(){this.g&&window.mys.pingback.send()}};var zd=class extends qd{constructor(a){super();this.context=a;this.pingback=new yd;this.g=new xd}};function Ad(a){var b=Bd;2==ab(b)||cb(cb(b,gb,1),eb,10)&&bb(cb(cb(b,gb,1),eb,10))||(b=0,mys.engine&&(b=mys.engine.stage()),0!=(b&1)?a.g.j():vd(a.h,"overallStart",()=>{a.g.j()}),0!=(b&4)&&a.g.h(),vd(a.h,"browserStart",()=>{}),vd(a.h,"browserReady",()=>{a.g.h()}),vd(a.h,"browserQuiet",()=>{}))}class Cd{constructor(a,b){this.g=a;this.h=b}};var Dd=class extends zd{constructor(a){super(a)}j(){if("true"===this.g.get("use_new_close_button")){rd();const a=mys.addon.getCountdownCloseButton();a.setCustomClose(()=>{window.oneAfmaInstance&&window.oneAfmaInstance.close()});a.setEnableSdkCloseFn(()=>{td()})}}h(){if("true"!==this.g.get("use_new_close_button")&&"interstitial"===this.g.get("layoutType")){var a=document.querySelector(".close-button");C.clo_e_t=Date.now();C.clo=a.id;a.addEventListener("click",pd);rd()}}};var Ed=class extends Dd{};{var Fd=b=>new Ed(b);const a=document.getElementById("mys-content");if(a){const b=new wd(a),c=Fd(b),d=new Cd(c,b);var Gd=d.g.g,Hd=ud(b.body,"runtime_data");if(Hd){const e=JSON.parse(Hd);for(const f in e)Gd.set(f,e[f])}var Bd,Id=ud(b.body,"render_config")||"[]";Bd=new ib(Id?JSON.parse(Id):null);Ad(d)}};}).call(this);
