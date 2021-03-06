#pragma once
#ifndef EFILEFORMATCONSTANTS_H_B1B8004C_8DF7_4A98_B8B2_3EEC414F1560
#define EFILEFORMATCONSTANTS_H_B1B8004C_8DF7_4A98_B8B2_3EEC414F1560

#include <QMap>
#include <QStringList>

namespace EFileFormatConstants {

const QMap<QString, QString> VideoFormatMap = {
    {"3g2", "video/3gpp2"},
    {"3gp", "video/3gpp"},
    {"avi", "video/x-msvideo"},
    {"asf", "video/x-ms-asf,video/ms-asf"},
    {"asx", "video/x-ms-asf,video/ms-asf"},
    {"dv", "video/x-dv"},
    {"dvd", "video/vnd.dvb.file"},
    {"f4v", "video/x-f4v"},
    {"fli", "video/x-fli"},
    {"flv", "video/x-flv"},
    {"fvt", "video/vnd.fvt"},
    {"h261", "video/h261"},
    {"h263", "video/h263"},
    {"h264", "video/h264"},
    {"jpgm", "video/jpm"},
    {"jpgv", "video/jpeg"},
    {"jpm", "video/jpm"},
    {"m1v", "video/mpeg"},
    {"m2v", "video/mpeg"},
    {"m3u", "application/vnd.apple.mpegurl,application/x-mpegurl"},
    {"m3u8", "application/vnd.apple.mpegurl,application/x-mpegurl"},
    {"m4a", "video/mp4"},
    {"m4b", "video/mp4"},
    {"m4p", "video/mp4"},
    {"m4r", "video/mp4"},
    {"m4u", "video/vnd.mpegurl"},
    {"m4v", "video/mp4"},
    {"mj2", "video/mj2"},
    {"mjp2", "video/mj2"},
    {"mk3d", "video/x-matroska"},
    {"mks", "video/x-matroska"},
    {"mkv", "video/x-matroska"},
    {"mng", "video/x-mng"},
    {"mov", "video/quicktime"},
    {"move", "video/x-sgi-movie"},
    {"mp4", "video/mp4"},
    {"mp4v", "video/mp4"},
    {"mpe", "video/mpeg"},
    {"mpeg", "video/mpeg"},
    {"mpg", "video/mpeg"},
    {"mpg4", "video/mp4"},
    {"mxu", "video/vnd.mpegurl"},
    {"ogv", "video/ogg"},
    {"pyv", "video/vnd.ms-playready.media.pyv"},
    {"qt", "video/quicktime"},
    {"rm", "application/vnd.rn-realmedia"},
    {"rmvb", "application/vnd.rn-realmedia-vbr"},
    {"smv", "video/x-smv"},
    {"ts", "video/mp2t"},
    {"uvh", "video/vnd.dece.hd"},
    {"uvm", "video/vnd.dece.mobile"},
    {"uvp", "video/vnd.dece.pd"},
    {"uvs", "video/vnd.dece.sd"},
    {"uvu", "video/vnd.uvvu.mp4"},
    {"uvv", "video/vnd.dece.video"},
    {"uvvh", "video/vnd.dece.hd"},
    {"uvvm", "video/vnd.dece.mobile"},
    {"uvvp", "video/vnd.dece.pd"},
    {"uvvs", "video/vnd.dece.sd"},
    {"uvvu", "video/vnd.uvvu.mp4"},
    {"uvvv", "video/vnd.dece.video"},
    {"viv", "video/vnd.vivo"},
    {"vob", "video/x-ms-vob"},
    {"webm", "video/webm"},
    {"wm", "video/x-ms-wm"},
    {"wmv", "video/x-ms-wmv"},
    {"wmx", "video/x-ms-wmx"},
    {"wvx", "video/x-ms-wvx"}
};

const QStringList VideoFileFormat = VideoFormatMap.keys();

const QMap<QString, QString> AudioFormatMap = {
    {"aac", "audio/x-aac"},
    {"adp", "audio/adpcm"},
    {"aif", "audio/x-aiff"},
    {"aifc", "audio/x-aiff"},
    {"aiff", "audio/x-aiff"},
    {"au", "audio/basic"},
    {"caf", "audio/x-caf"},
    {"dra", "audio/vnd.dra"},
    {"dts", "audio/vnd.dts"},
    {"dtshd", "audio/vnd.dts.hd"},
    {"eol", "audio/vnd.digital-winds"},
    {"flac", "audio/x-flac"},
    {"kar", "audio/midi"},
    {"lvp", "audio/vnd.lucent.voice"},
    {"m2a", "audio/mpeg"},
    {"m3a", "audio/mpeg"},
    {"m3u", "audio/x-mpegurl"},
    {"m3u8", "application/vnd.apple.mpegurl"},
    {"m4a", "audio/mp4"},
    {"mid", "audio/midi"},
    {"midi", "audio/midi"},
    {"mka", "audio/x-matroska"},
    {"mogg", "audio/mpeg"},
    {"mp2", "audio/mpeg"},
    {"mp2a", "audio/mpeg"},
    {"mp3", "audio/mpeg,application/octet-stream"},
    {"mp4", "audio/mp4"},
    {"mp4a", "audio/mp4"},
    {"mpga", "audio/mpeg"},
    {"oga", "audio/ogg"},
    {"ogg", "audio/ogg"},
    {"opus", "audio/ogg"},
    {"pls", "application/pls+xml"},
    {"ra", "audio/x-pn-realaudio"},
    {"ram", "audio/x-pn-realaudio"},
    {"rip", "audio/vnd.rip"},
    {"rmi", "audio/midi"},
    {"rmp", "audio/x-pn-realaudio-plugin"},
    {"s3m", "audio/s3m"},
    {"sil", "audio/silk"},
    {"snd", "audio/basic"},
    {"spx", "audio/ogg"},
    {"uva", "audio/vnd.dece.audio"},
    {"uvva", "audio/vnd.dece.audio"},
    {"wav", "audio/x-ms-wax"},
    {"wax", "audio/x-wav"},
    {"weba", "audio/webm"},
    {"wma", "audio/x-ms-wma"},
    {"xm", "audio/xm"},
    {"xspf", "application/xspf+xml"}
};

const QStringList AudioFileFormat = AudioFormatMap.keys();

const QMap<QString, QString> ImageFormatMap = {
    {"bmp", "image/bmp"},
    {"gif", "image/gif"},
    {"jpeg", "image/jpeg"},
    {"jpg", "image/jpeg"},
    {"png", "image/png"},
    {"ico", "image/not-support-show"},
    {"icns", "image/not-support-show"},
    {"album", "image/not-support-show"}
};

const QStringList ImageFileFormat = ImageFormatMap.keys();

const QStringList SupportedImageFormat({"*.bmp", "*.gif", "*.jpeg", "*.jpg", "*.png"});

const QMap<QString, QString> WordFormatMap = {
    {"doc", "application/msword,application/zip,text/plain"},
    {"docm", "application/vnd.ms-word.document.macroenabled.12,application/zip,text/plain"},
    {"docx", "application/vnd.openxmlformats-officedocument.wordprocessingml.document,application/zip,text/plain"},
    {"dot", "application/msword,application/zip,text/plain"},
    {"dotm", "application/vnd.ms-word.template.macroenabled.12,application/zip,text/plain"},
    {"dotx", "application/vnd.openxmlformats-officedocument.wordprocessingml.template,application/zip,text/plain"}
};

const QStringList WordFileFormat = WordFormatMap.keys();

const QMap<QString, QString> ExcelFormatMap = {
    {"xla", "application/vnd.ms-excel,application/zip,text/plain"},
    {"xlam", "application/vnd.ms-excel.addin.macroenabled.12,application/zip,text/plain"},
    {"xlc", "application/vnd.ms-excel,application/zip,text/plain"},
    {"xlm", "application/vnd.ms-excel,application/zip,text/plain"},
    {"xls", "application/vnd.ms-excel,application/zip,text/plain"},
    {"xlsb", "application/vnd.ms-excel.sheet.binary.macroenabled.12,application/zip,text/plain"},
    {"xlsm", "application/vnd.ms-excel.sheet.macroenabled.12,application/zip,text/plain"},
    {"xlsx", "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet,application/zip,text/plain"},
    {"xlt", "application/vnd.ms-excel,application/zip,text/plain"},
    {"xltm", "application/vnd.ms-excel.template.macroenabled.12,application/zip,text/plain"},
    {"xltx", "application/vnd.openxmlformats-officedocument.spreadsheetml.template,application/zip,text/plain"},
    {"xlw", "application/vnd.ms-excel,application/zip,text/plain"}
};

const QStringList ExcelFileFormat = ExcelFormatMap.keys();

const QMap<QString, QString> PowerPointFormatMap = {
    {"pot", "application/vnd.ms-powerpoint,application/zip,text/plain"},
    {"pps", "application/vnd.ms-powerpoint,application/zip,text/plain"},
    {"ppt", "application/vnd.ms-powerpoint,application/zip,text/plain"},
    {"potm", "application/vnd.ms-powerpoint.template.macroenabled.12,application/zip,text/plain"},
    {"potx", "application/vnd.openxmlformats-officedocument.presentationml.template,application/zip,text/plain"},
    {"ppam", "application/vnd.ms-powerpoint.addin.macroenabled.12,application/zip,text/plain"},
    {"ppsm", "application/vnd.ms-powerpoint.slideshow.macroenabled.12,application/zip,text/plain"},
    {"ppsx", "application/vnd.openxmlformats-officedocument.presentationml.slideshow,application/zip,text/plain"},
    {"pptm", "application/vnd.ms-powerpoint.presentation.macroenabled.12,application/zip,text/plain"},
    {"pptx", "application/vnd.openxmlformats-officedocument.presentationml.presentation,application/zip,text/plain"},
    {"sldm", "application/vnd.ms-powerpoint.slide.macroenabled.12,application/zip,text/plain"}
};

const QStringList PowerPointFileFormat = PowerPointFormatMap.keys();

const QMap<QString, QString> CompressedFileFormatMap = {
    {"7z", "application/x-7z-compressed,application/octet-stream"},
    {"boz", "application/x-bzip2"},
    {"bz2", "application/x-bzip2"},
    {"bzip2", "application/x-bzip2"},
    {"cab", "application/vnd.ms-cab-compressed"},
    {"cpio", "application/x-cpio"},
    {"deb", "application/x-debian-package"},
    {"dmg", "application/x-apple-diskimage"},
    {"gzip", "application/gzip"},
    {"iso", "application/x-iso9660-image"},
    {"lha", "application/x-lzh-compressed"},
    {"lzh", "application/x-lzh-compressed"},
    {"rar", "application/x-rar-compressed"},
    {"tar", "application/x-ta"},
    {"udeb", "application/x-debian-package"},
    {"xar", "application/vnd.xara"},
    {"xz", "application/x-xz"},
    {"zip", "application/zip"}
};

const QStringList CompressedFileFormat = CompressedFileFormatMap.keys();

const QMap<QString, QString> TextFormatMap = {
    {"3dml", "text/vnd.in3d.3dml,text/plain"},
    {"appcache", "text/cache-manifest,text/plain"},
    {"asm", "text/x-asm,text/plain"},
    {"c", "text/x-c,text/plain"},
    {"cc", "text/x-c,text/plain"},
    {"conf", "text/plain"},
    {"cpp", "text/x-c,text/plain"},
    {"css", "text/css,text/plain"},
    {"csv", "text/csv,text/plain"},
    {"curl", "text/vnd.curl,text/plain"},
    {"cxx", "text/x-c,text/plain"},
    {"dcurl", "text/vnd.curl.dcurl,text/plain"},
    {"def", "text/plain"},
    {"dic", "text/x-c,text/plain"},
    {"dsc", "text/prs.lines.tag,text/plain"},
    {"etx", "text/x-setext,text/plain"},
    {"f", "text/x-fortran,text/plain"},
    {"f77", "text/x-fortran,text/plain"},
    {"f90", "text/x-fortran,text/plain"},
    {"flx", "text/vnd.fmi.flexstor,text/plain"},
    {"fly", "text/vnd.fly,text/plain"},
    {"for", "text/x-fortran,text/plain"},
    {"gv", "text/vnd.graphviz,text/plain"},
    {"h", "text/x-c,text/plain"},
    {"hh", "text/x-c,text/plain"},
    {"html", "text/html,text/plain"},
    {"htm", "text/html,text/plain"},
    {"ics", "text/calendar,text/plain"},
    {"ifb", "text/calendar,text/plain"},
    {"in", "text/plain"},
    {"jad", "text/vnd.sun.j2me.app-descriptor,text/plain"},
    {"java", "text/x-java-source,text/plain"},
    {"js", "application/javascript,text/plain"},
    {"json", "application/json,text/plain"},
    {"list", "text/plain"},
    {"log", "text/plain"},
    {"man", "text/troff,text/plain"},
    {"mcurl", "text/vnd.curl.mcurl,text/plain"},
    {"me", "text/troff,text/plain"},
    {"ms", "text/troff,text/plain"},
    {"n3", "text/n3,text/plain"},
    {"nfo", "text/x-nfo,text/plain"},
    {"opml", "text/x-opml,text/plain"},
    {"p", "text/x-pascal,text/plain"},
    {"pas", "text/x-pascal,text/plain"},
    {"qml", "text/plain"},
    {"roff", "text/troff,text/plain"},
    {"rtx", "text/richtext,text/plain"},
    {"s", "text/x-asm,text/plain"},
    {"scurl", "text/vnd.curl.scurl,text/plain"},
    {"sfv", "text/x-sfv,text/plain"},
    {"sgm", "text/sgml,text/plain"},
    {"sgml", "text/sgml,text/plain"},
    {"spot", "text/vnd.in3d.spot,text/plain"},
    {"sub", "text/vnd.dvb.subtitle,text/plain"},
    {"t", "text/troff,text/plain"},
    {"text", "text/plain"},
    {"tr", "text/troff,text/plain"},
    {"tsv", "text/tab-separated-values,text/plain"},
    {"ttl", "text/turtle,text/plain"},
    {"txt", "text/plain"},
    {"uri", "text/uri-list,text/plain"},
    {"uris", "text/uri-list,text/plain"},
    {"urls", "text/uri-list,text/plain"},
    {"uu", "text/x-uuencode,text/plain"},
    {"vcard", "text/vcard,text/plain"},
    {"vcf", "text/x-vcard,text/plain"},
    {"vcs", "text/x-vcalendar,text/plain"},
    {"wml", "text/vnd.wap.wml,text/plain"},
    {"wmls", "text/vnd.wap.wmlscript,text/plain"},
};

const QStringList TextFileFormat = TextFormatMap.keys();

}

#endif // EFILEFORMATCONSTANTS_H_B1B8004C_8DF7_4A98_B8B2_3EEC414F1560
