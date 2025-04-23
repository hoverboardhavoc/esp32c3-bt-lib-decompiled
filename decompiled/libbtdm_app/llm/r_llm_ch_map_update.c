/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  iVar5 = _p_llm_env;
  iVar11 = _p_llm_env + 0x1d;
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x22c))(*(code **)(_r_ip_funcs_p + 0x22c));
  cVar2 = DAT_00012074;
  iVar13 = _p_llm_env;
  uVar14 = (uint)_DAT_0001206e;
  uVar15 = (uint)_DAT_00012070;
  pcVar6 = (char *)(iVar4 + 0x94);
  uVar7 = 0;
  do {
    iVar8 = ((int)uVar7 >> 3) + iVar5;
    uVar12 = uVar7 & 7;
    if (((int)(uint)*(byte *)(iVar8 + 0x18) >> uVar12 & 1U) == 0) {
_L376:
      bVar10 = ~(byte)(1 << uVar12) & *(byte *)(iVar8 + 0x1d);
_L375:
      *(byte *)(iVar8 + 0x1d) = bVar10;
    }
    else if (*(char *)(iVar13 + 0xd9) != '\0') {
      uVar9 = iVar3 - *(int *)(uVar7 * 4 + iVar4) & 0xfffffff;
      if (uVar9 < uVar14) {
        if (*pcVar6 <= cVar2) goto _L376;
      }
      else {
        *pcVar6 = '\0';
        if (uVar15 < uVar9) {
          bVar10 = (byte)(1 << uVar12) | *(byte *)(iVar8 + 0x1d);
          goto _L375;
        }
      }
    }
    uVar7 = uVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar7 != 0x25);
  uVar7 = (**(code **)(_r_modules_funcs_p + 0xc))(iVar11,*(code **)(_r_modules_funcs_p + 0xc));
  if (uVar7 < 2) {
    uVar14 = 0;
    do {
      iVar13 = ((int)uVar14 >> 3) + iVar5;
      uVar15 = uVar14 & 7;
      if ((((int)(uint)*(byte *)(iVar13 + 0x18) >> uVar15 & 1U) != 0) &&
         (((int)(uint)*(byte *)(iVar13 + 0x1d) >> uVar15 & 1U) == 0)) {
        *(byte *)(iVar13 + 0x1d) = *(byte *)(iVar13 + 0x1d) | (byte)(1 << uVar15);
        uVar7 = uVar7 + 1 & 0xff;
        if (1 < uVar7) break;
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 != 0x25);
  }
  uVar7 = 0;
  bVar1 = false;
  (**(code **)(_r_ip_funcs_p + 0x234))(iVar11,*(code **)(_r_ip_funcs_p + 0x234));
  do {
    iVar5 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((int)(uint)*(byte *)(iVar5 + 0xd) <= (int)uVar7) {
      if (!bVar1) {
        *(undefined1 *)(_p_llm_env + 0x22) = 0;
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x00011204. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_modules_funcs_p + 0xc4))
                (4,0,(uint)_DAT_0001206c * 100,*(code **)(_r_modules_funcs_p + 0xc4));
      return;
    }
    iVar5 = *(int *)(_p_llm_env + 8) + uVar7 * 0x44;
    if (*(char *)(iVar5 + 0x40) == '\t') {
      if (*(char *)(iVar5 + 0x28) == '\0') {
        (**(code **)(_r_modules_funcs_p + 0xe4))
                  (2,(uVar7 & 0xff) << 8 | 1,0,*(code **)(_r_modules_funcs_p + 0xe4));
        bVar1 = true;
        goto _L361;
      }
    }
    else {
_L361:
      if (*(char *)(*(int *)(_p_llm_env + 8) + uVar7 * 0x44 + 0x40) == '\f') {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
        if (*(char *)(iVar5 + 0x18) == '\0') {
          (**(code **)(_r_plf_funcs_p + 8))(0,"llm.c",0x502,*(code **)(_r_plf_funcs_p + 8));
        }
        (**(code **)(_r_ip_funcs_p + 0x2c8))(uVar7 & 0xff,iVar11,*(code **)(_r_ip_funcs_p + 0x2c8));
      }
    }
    uVar7 = uVar7 + 1;
  } while( true );
}

