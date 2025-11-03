/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  char *pcVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  iVar5 = _p_llm_env;
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x22c))(*(code **)(_r_ip_funcs_p + 0x22c));
  cVar2 = DAT_00012074;
  iVar12 = _p_llm_env;
  uVar14 = (uint)_DAT_0001206e;
  uVar15 = (uint)_DAT_00012070;
  iVar13 = iVar5 + 0x1d;
  pcVar6 = (char *)(iVar4 + 0x94);
  uVar7 = 0;
  do {
    iVar8 = ((int)uVar7 >> 3) + iVar5;
    uVar11 = uVar7 & 7;
    if (((int)(uint)*(byte *)(iVar8 + 0x18) >> uVar11 & 1U) == 0) {
_L414:
      bVar10 = ~(byte)(1 << uVar11) & *(byte *)(iVar8 + 0x1d);
_L413:
      *(byte *)(iVar8 + 0x1d) = bVar10;
    }
    else if (*(char *)(iVar12 + 0xd9) != '\0') {
      uVar9 = iVar3 - *(int *)(uVar7 * 4 + iVar4) & 0xfffffff;
      if (uVar9 < uVar14) {
        if (*pcVar6 <= cVar2) goto _L414;
      }
      else {
        *pcVar6 = '\0';
        if (uVar15 < uVar9) {
          bVar10 = (byte)(1 << uVar11) | *(byte *)(iVar8 + 0x1d);
          goto _L413;
        }
      }
    }
    uVar7 = uVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar7 != 0x25);
  uVar7 = (**(code **)(_r_modules_funcs_p + 0xc))(iVar13,*(code **)(_r_modules_funcs_p + 0xc));
  if (uVar7 < 2) {
    uVar14 = 0;
    do {
      iVar12 = ((int)uVar14 >> 3) + iVar5;
      uVar15 = uVar14 & 7;
      if ((((int)(uint)*(byte *)(iVar12 + 0x18) >> uVar15 & 1U) != 0) &&
         (((int)(uint)*(byte *)(iVar12 + 0x1d) >> uVar15 & 1U) == 0)) {
        *(byte *)(iVar12 + 0x1d) = *(byte *)(iVar12 + 0x1d) | (byte)(1 << uVar15);
        if (uVar7 == 1) break;
        uVar7 = 1;
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 != 0x25);
  }
  bVar1 = false;
  (**(code **)(_r_ip_funcs_p + 0x234))(iVar13,*(code **)(_r_ip_funcs_p + 0x234));
  for (uVar7 = 0; iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
      (int)uVar7 < (int)(uint)*(byte *)(iVar5 + 0xd); uVar7 = uVar7 + 1) {
    iVar5 = *(int *)(_p_llm_env + 8) + uVar7 * 0x44;
    if ((*(char *)(iVar5 + 0x40) == '\t') && (*(char *)(iVar5 + 0x28) == '\0')) {
      (**(code **)(_r_modules_funcs_p + 0xe4))
                (2,(uVar7 & 0xff) << 8 | 1,0,*(code **)(_r_modules_funcs_p + 0xe4));
      bVar1 = true;
    }
    if (*(char *)(*(int *)(_p_llm_env + 8) + uVar7 * 0x44 + 0x40) == '\f') {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar5 + 0x18) == '\0') {
        (**(code **)(_r_plf_funcs_p + 8))(0,"llm.c",0x527,*(code **)(_r_plf_funcs_p + 8));
      }
      (**(code **)(_r_ip_funcs_p + 0x2c8))(uVar7 & 0xff,iVar13,*(code **)(_r_ip_funcs_p + 0x2c8));
    }
  }
  if (!bVar1) {
    *(undefined1 *)(_p_llm_env + 0x22) = 0;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000112d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xc4))
            (4,0,(uint)_DAT_0001206c * 100,*(code **)(_r_modules_funcs_p + 0xc4));
  return;
}

