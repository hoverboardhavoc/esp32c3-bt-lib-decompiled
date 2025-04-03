/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> llm.o -> r_llm_ch_map_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_ch_map_update(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  iVar5 = _p_llm_env;
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x22c))(*(code **)(_r_ip_funcs_p + 0x22c));
  cVar2 = DAT_00012074;
  iVar11 = _p_llm_env;
  uVar13 = (uint)_DAT_0001206e;
  uVar14 = (uint)_DAT_00012070;
  iVar12 = iVar5 + 0x1d;
  uVar6 = 0;
  do {
    iVar7 = ((int)uVar6 >> 3) + iVar5;
    uVar10 = uVar6 & 7;
    if (((int)(uint)*(byte *)(iVar7 + 0x18) >> uVar10 & 1U) == 0) {
_L416:
      bVar9 = ~(byte)(1 << uVar10) & *(byte *)(iVar7 + 0x1d);
_L415:
      *(byte *)(iVar7 + 0x1d) = bVar9;
    }
    else if (*(char *)(iVar11 + 0xd9) != '\0') {
      uVar8 = iVar3 - *(int *)(uVar6 * 4 + iVar4) & 0xfffffff;
      if (uVar8 < uVar13) {
        if (*(char *)(iVar4 + uVar6 + 0x94) <= cVar2) goto _L416;
      }
      else {
        *(undefined1 *)(iVar4 + uVar6 + 0x94) = 0;
        if (uVar14 < uVar8) {
          bVar9 = (byte)(1 << uVar10) | *(byte *)(iVar7 + 0x1d);
          goto _L415;
        }
      }
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 != 0x25);
  uVar6 = (**(code **)(_r_modules_funcs_p + 0xc))(iVar12,*(code **)(_r_modules_funcs_p + 0xc));
  if (uVar6 < 2) {
    uVar13 = 0;
    do {
      iVar11 = ((int)uVar13 >> 3) + iVar5;
      uVar14 = uVar13 & 7;
      if ((((int)(uint)*(byte *)(iVar11 + 0x18) >> uVar14 & 1U) != 0) &&
         (((int)(uint)*(byte *)(iVar11 + 0x1d) >> uVar14 & 1U) == 0)) {
        *(byte *)(iVar11 + 0x1d) = (byte)(1 << uVar14) | *(byte *)(iVar11 + 0x1d);
        if (uVar6 == 1) break;
        uVar6 = 1;
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 != 0x25);
  }
  bVar1 = false;
  (**(code **)(_r_ip_funcs_p + 0x234))(iVar12,*(code **)(_r_ip_funcs_p + 0x234));
  for (uVar6 = 0; iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
      (int)uVar6 < (int)(uint)*(byte *)(iVar5 + 0xd); uVar6 = uVar6 + 1) {
    iVar5 = *(int *)(_p_llm_env + 8) + uVar6 * 0x44;
    if ((*(char *)(iVar5 + 0x40) == '\t') && (*(char *)(iVar5 + 0x28) == '\0')) {
      (**(code **)(_r_modules_funcs_p + 0xe4))
                (2,(uVar6 & 0xff) << 8 | 1,0,*(code **)(_r_modules_funcs_p + 0xe4));
      bVar1 = true;
    }
    if (*(char *)(*(int *)(_p_llm_env + 8) + uVar6 * 0x44 + 0x40) == '\f') {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar5 + 0x18) == '\0') {
        (**(code **)(_r_plf_funcs_p + 8))(0,"llm.c",0x502,*(code **)(_r_plf_funcs_p + 8));
      }
      (**(code **)(_r_ip_funcs_p + 0x2c8))(uVar6 & 0xff,iVar12,*(code **)(_r_ip_funcs_p + 0x2c8));
    }
  }
  if (!bVar1) {
    *(undefined1 *)(_p_llm_env + 0x22) = 0;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00011274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xc4))(4,0,(uint)_DAT_0001206c * 100);
  return;
}

