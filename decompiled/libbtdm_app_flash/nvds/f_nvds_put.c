/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> nvds.o -> f_nvds_put
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_nvds_put(uint param_1,size_t param_2,void *param_3)

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
  undefined1 auStack_130 [268];
  
  if (sdk_cfg_priv_opts == '\0') {
    return 7;
  }
  iStack_134 = 4;
  iVar4 = 0;
  while (iVar1 = iStack_134, iVar2 = r_nvds_walk_tag(iStack_134,&bStack_138,&iStack_134), iVar2 == 0
        ) {
    if ((bStack_137 & 5) == 4) {
      if (bStack_138 == param_1) {
        if ((bStack_137 & 2) == 0) {
          return 5;
        }
        (*nvds_env)(iVar1 + 3,bStack_136,auStack_130,nvds_env);
        if ((bStack_136 == param_2) && (iVar2 = memcmp(param_3,auStack_130,param_2), iVar2 == 0))
        goto _L74;
        bStack_139 = bStack_137 & 0xfb;
        (*DAT_0001069c)(iVar1 + 1,&bStack_139,DAT_0001069c);
      }
      else {
        iVar4 = iVar4 + bStack_136 + 3;
      }
    }
  }
  if (DAT_000106a8 < iVar1 + 6 + param_2) {
    nvds_temp_buf = (**(code **)(_r_osi_funcs_p + 0x78))(0x800,*(code **)(_r_osi_funcs_p + 0x78));
    if (nvds_temp_buf != 0) {
      r_nvds_purge(iVar4,nvds_temp_buf);
      (**(code **)(_r_osi_funcs_p + 0x7c))(nvds_temp_buf,*(code **)(_r_osi_funcs_p + 0x7c));
      nvds_temp_buf = 0;
      iVar1 = iVar4 + 4;
      if (param_2 + 3 + iVar1 <= DAT_000106a8 - 1) goto _L70;
    }
    uVar3 = 3;
  }
  else {
_L70:
    (*DAT_0001069c)(iVar1 + 3,param_2,param_3,DAT_0001069c);
    bStack_137 = 6;
    bStack_138 = (byte)param_1;
    bStack_136 = (byte)param_2;
    (*DAT_0001069c)(iVar1,3,&bStack_138,DAT_0001069c);
_L74:
    uVar3 = 0;
  }
  return uVar3;
}

