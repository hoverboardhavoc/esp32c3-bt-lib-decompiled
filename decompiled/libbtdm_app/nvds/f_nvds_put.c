/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> nvds.o -> f_nvds_put
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_nvds_put(uint param_1,size_t param_2,void *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bStack_139;
  byte bStack_138;
  byte bStack_137;
  byte bStack_136;
  int iStack_134;
  undefined1 auStack_130 [264];
  
  if (sdk_cfg_priv_opts == '\0') {
    return 7;
  }
  iStack_134 = 4;
  iVar4 = 0;
  while (iVar2 = iStack_134,
        iVar3 = (**(code **)(_r_modules_funcs_p + 0x260))
                          (iStack_134,&bStack_138,&iStack_134,*(code **)(_r_modules_funcs_p + 0x260)
                          ), iVar3 == 0) {
    if ((bStack_137 & 5) == 4) {
      if (bStack_138 == param_1) {
        if ((bStack_137 & 2) == 0) {
          return 5;
        }
        (*nvds_env)(iVar2 + 3,bStack_136,auStack_130,nvds_env);
        if ((bStack_136 == param_2) && (iVar3 = memcmp(param_3,auStack_130,param_2), iVar3 == 0)) {
          return 0;
        }
        bStack_139 = bStack_137 & 0xfb;
        (*DAT_000106f4)(iVar2 + 1,1,&bStack_139,DAT_000106f4);
      }
      else {
        iVar4 = iVar4 + bStack_136 + 3;
      }
    }
  }
  if (DAT_00010700 < iVar2 + 6 + param_2) {
    nvds_temp_buf = (**(code **)(_r_osi_funcs_p + 0x78))(0x800,*(code **)(_r_osi_funcs_p + 0x78));
    if (nvds_temp_buf != 0) {
      (**(code **)(_r_modules_funcs_p + 0x254))
                (iVar4,nvds_temp_buf,*(code **)(_r_modules_funcs_p + 0x254));
      (**(code **)(_r_osi_funcs_p + 0x7c))(nvds_temp_buf,*(code **)(_r_osi_funcs_p + 0x7c));
      nvds_temp_buf = 0;
      iVar2 = iVar4 + 4;
      if (param_2 + 3 + iVar2 <= DAT_00010700 - 1) goto _L69;
    }
    uVar1 = 3;
  }
  else {
_L69:
    (*DAT_000106f4)(iVar2 + 3,param_2,param_3,DAT_000106f4);
    bStack_137 = 6;
    bStack_138 = (byte)param_1;
    bStack_136 = (byte)param_2;
    (*DAT_000106f4)(iVar2,3,&bStack_138,DAT_000106f4);
    uVar1 = 0;
  }
  return uVar1;
}

