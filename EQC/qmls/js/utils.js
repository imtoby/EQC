
/**
 * Returns a number whose value is limited to the given range.
 *
 * @method Number.prototype.bound
 * @param {Number} min The lower boundary
 * @param {Number} max The upper boundary
 * @return {Number} A number in the range (min, max)
 */
Number.prototype.bound = function(min, max) {
    return Math.min(Math.max(this, min), max);
};

/**
 * Returns a modulo value which is always positive.
 *
 * @method Number.prototype.mod
 * @param {Number} n The divisor
 * @return {Number} A modulo value
 */
Number.prototype.mod = function(n) {
    return ((this % n) + n) % n;
};

/**
 * Makes a number string with leading zeros.
 *
 * @method String.prototype.padZero
 * @param {Number} length The length of the output string
 * @return {String} A string with leading zeros
 */
String.prototype.padZero = function(length){
    var s = this;
    while (s.length < length) {
        s = '0' + s;
    }
    return s;
};

/**
 * Makes a number string with leading zeros.
 *
 * @method Number.prototype.padZero
 * @param {Number} length The length of the output string
 * @return {String} A string with leading zeros
 */
Number.prototype.padZero = function(length){
    return String(this).padZero(length);
};

/**
 * Checks whether the string is a number.
 *
 * @method String.prototype.isNumber
 * @param {String} string The string to search for
 * @return {Boolean} True if the string is a number
 */
String.prototype.isNumber = function() {
    var reg = /^[0-9]*$/;
    return reg.test(this);
}

Object.defineProperties(Array.prototype, {
    /**
     * Checks whether the two arrays are same.
     *
     * @method Array.prototype.equals
     * @param {Array} array The array to compare to
     * @return {Boolean} True if the two arrays are same
     */
    equals: {
        enumerable: false,
        value: function(array) {
            if (!array || this.length !== array.length) {
                return false;
            }
            for (var i = 0; i < this.length; i++) {
                if (this[i] instanceof Array && array[i] instanceof Array) {
                    if (!this[i].equals(array[i])) {
                        return false;
                    }
                } else if (this[i] !== array[i]) {
                    return false;
                }
            }
            return true;
        }
    },
    /**
     * Makes a shallow copy of the array.
     *
     * @method Array.prototype.clone
     * @return {Array} A shallow copy of the array
     */
    clone: {
        enumerable: false,
        value: function() {
            return this.slice(0);
        }
    },
    /**
     * Checks whether the array contains a given element.
     *
     * @method Array.prototype.contains
     * @param {Any} element The element to search for
     * @return {Boolean} True if the array contains a given element
     */
    contains : {
        enumerable: false,
        value: function(element) {
            return this.indexOf(element) >= 0;
        }
    }
});

/**
 * Checks whether the string contains a given string.
 *
 * @method String.prototype.contains
 * @param {String} string The string to search for
 * @return {Boolean} True if the string contains a given string
 */
String.prototype.contains = function(string) {
    return this.indexOf(string) >= 0;
};

/**
 * Generates a random integer in the range (0, max-1).
 *
 * @static
 * @method Math.randomInt
 * @param {Number} max The upper boundary (excluded)
 * @return {Number} A random integer
 */
Math.randomInt = function(max) {
    return Math.floor(max * Math.random());
};

/**
 * Trim spaces at the beginning and end of string.
 *
 * @method String.prototype.trim
 * @return a {String} no space at the beginning and end
 */
String.prototype.trim = function()
{
    return this.replace(/(^\s*)|(\s*$)/g, "");
}

/**
 * Trim spaces at the beginning of string.
 *
 * @method String.prototype.beginningTrim
 * @return a {String} no space at the beginning
 */
String.prototype.beginningTrim = function()
{
    return this.replace(/(^\s*)/g, "");
}

/**
 * Trim spaces at the end of string.
 *
 * @method String.prototype.endTrim
 * @return a {String} no space at the end
 */
String.prototype.endTrim = function()
{
    return this.replace(/(\s*$)/g, "");
}

/**
 * Checks whether the string is a JSON string
 *
 * @method String.prototype.isJson
 * @return {Boolean} True if the string is a JSON
 */
String.prototype.isJson = function()
{
    try {
        JSON.parse(this);
    } catch (e) {
        return false;
    }
    return true;
}

/**
 * Removes n characters from the end of the string
 *
 * @method String.chop
 * @param {Number} n chars
 * @return {String} A string which remove n chars from the end
 */
String.prototype.chop = function(n)
{
    if (n >= this.size()) {
        return ""
    } else if (n <= 0) {
        return this
    }
    return this.slice(0, -n);
}

/**
 * Returns true if the string starts with s; otherwise returns false
 *
 * @method String.startsWith
 * @param {String} prefix
 * @return {Boolean}
 */
String.prototype.startsWith = function(prefix)
{
    return this.slice(0, prefix.length) === prefix
}

/**
 * Returns true if the string ends with s; otherwise returns false
 *
 * @method String.endsWith
 * @param {String} suffix
 * @return {Boolean}
 */
String.prototype.endsWith = function(suffix)
{
    return this.indexOf(suffix, this.length - suffix.length) !== -1;
}
