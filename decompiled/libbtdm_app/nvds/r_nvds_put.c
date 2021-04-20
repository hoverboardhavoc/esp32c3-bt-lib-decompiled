/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> nvds.o -> r_nvds_put
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_nvds_put(uint param_1,size_t param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  byte bStack_139;
  byte bStack_138;
  byte bStack_137;
  byte bStack_136;
  int iStack_134;
  undefined1 auStack_130 [260];
  
  if (sdk_cfg_priv_opts == '\0') {
    return 7;
  }
  iStack_134 = 4;
  iVar4 = 0;
  while (iVar1 = iStack_134,
        iVar2 = (**(code **)(_r_modules_funcs_p + 0x260))
                          (iStack_134,&bStack_138,&iStack_134,*(code **)(_r_modules_funcs_p + 0x260)
                          ), iVar2 == 0) {
    if ((bStack_137 & 5) == 4) {
      if (bStack_138 == param_1) {
        if ((bStack_137 & 2) == 0) {
          return 5;
        }
        (*_LANCHOR0)(iVar1 + 3,bStack_136,auStack_130,_LANCHOR0);
        if ((bStack_136 == param_2) && (iVar2 = memcmp(param_3,auStack_130,param_2), iVar2 == 0)) {
          return 0;
        }
        bStack_139 = bStack_137 & 0xfb;
        (*DAT_000106a4)(iVar1 + 1,1,&bStack_139,DAT_000106a4);
      }
      else {
        iVar4 = iVar4 + bStack_136 + 3;
      }
    }
  }
  if (DAT_000106b0 < param_2 + 6 + iVar1) {
    _LANCHOR2 = (**(code **)(_r_osi_funcs_p + 0x78))(0x800,*(code **)(_r_osi_funcs_p + 0x78));
    if (_LANCHOR2 != 0) {
      (**(code **)(_r_modules_funcs_p + 0x254))
                (iVar4,_LANCHOR2,*(code **)(_r_modules_funcs_p + 0x254));
      (**(code **)(_r_osi_funcs_p + 0x7c))(_LANCHOR2,*(code **)(_r_osi_funcs_p + 0x7c));
      _LANCHOR2 = 0;
      iVar1 = iVar4 + 4;
      if (param_2 + 3 + iVar1 <= DAT_000106b0 - 1) goto _L65;
    }
    uVar3 = 3;
  }
  else {
_L65:
    (*DAT_000106a4)(iVar1 + 3,param_2,param_3,DAT_000106a4);
    bStack_137 = 6;
    bStack_138 = (byte)param_1;
    bStack_136 = (byte)param_2;
    (*DAT_000106a4)(iVar1,3,&bStack_138,DAT_000106a4);
    uVar3 = 0;
  }
  return uVar3;
}

