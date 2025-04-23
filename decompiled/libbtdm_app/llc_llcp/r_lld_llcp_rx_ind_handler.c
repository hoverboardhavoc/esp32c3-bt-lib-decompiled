/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_llcp.o -> r_lld_llcp_rx_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_llcp_rx_ind_handler(undefined2 *param_1,uint param_2)

{
  int iVar1;
  ushort *puVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  char cStack_7f;
  undefined2 uStack_7e;
  byte abStack_7c [28];
  byte abStack_60 [60];
  
  uVar9 = param_2 >> 8;
  iVar8 = *(int *)(&llc_env + uVar9 * 4);
  if (iVar8 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(uVar9,0,"llc_llcp.c",0xfd,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x5c4))(*(code **)(_r_ip_funcs_p + 0x5c4));
  if ((iVar8 == 0) || ((*(ushort *)(iVar8 + 0x42) & 0x40) != 0)) goto _L26;
  memcpy(abStack_7c,*(void **)(param_1 + 4),0x1b);
  abStack_60[0] = abStack_7c[0];
  if (abStack_7c[0] < 0x23) {
    iVar7 = (uint)abStack_7c[0] * 0xc + iVar1;
    if (*(ushort *)(iVar7 + 8) == (ushort)*(byte *)(param_1 + 1)) {
      uStack_7e = 0x30;
      iVar7 = (**(code **)(_r_modules_funcs_p + 0x18))
                        (abStack_60,abStack_7c,&uStack_7e,*(undefined4 *)(iVar7 + 4),
                         *(code **)(_r_modules_funcs_p + 0x18));
      if (iVar7 != 0) {
        iVar7 = 0x1e;
      }
      cStack_7f = (char)iVar7;
      bVar4 = *(byte *)(iVar8 + 0x44) & 3;
      if (bVar4 != 2) {
        if (bVar4 == 3) {
          bVar5 = *(byte *)(iVar1 + (uint)abStack_60[0] * 0xc + 10) & 8;
        }
        else {
          bVar5 = *(byte *)((uint)abStack_60[0] * 0xc + iVar1 + 10);
          if (bVar4 == 1) {
            if ((bVar5 & 4) == 0) {
              pcVar6 = *(code **)(_r_ip_funcs_p + 0x55c);
              goto _L66;
            }
            goto _L30;
          }
          bVar5 = bVar5 & 1;
        }
        if (bVar5 == 0) goto _L26;
      }
    }
    else {
      cStack_7f = '\x19';
    }
_L30:
    if (cStack_7f == '\0') {
      if (0x22 < abStack_60[0]) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (param_2,"llc_llcp.c",0x18b,*(code **)(_r_plf_funcs_p + 0xc));
      }
      cStack_7f = (**(code **)(_r_ip_funcs_p + 0x8ec))
                            (uVar9,abStack_60,*param_1,*(code **)(_r_ip_funcs_p + 0x8ec));
      pcVar6 = (code *)(**(code **)(_r_ip_funcs_p + 0x8e8))
                                 (abStack_60[0],*(code **)(_r_ip_funcs_p + 0x8e8));
      if ((cStack_7f == '\0') && (pcVar6 != (code *)0x0)) {
        cStack_7f = (*pcVar6)(uVar9,abStack_60,*param_1,pcVar6);
        (**(code **)(_r_ip_funcs_p + 0x8f0))
                  (&cStack_7f,uVar9,abStack_60,*param_1,*(code **)(_r_ip_funcs_p + 0x8f0));
      }
      if (((abStack_60[0] == 6) && (cStack_7f == '\0')) && ((*(ushort *)(iVar8 + 0x42) & 1) == 0)) {
        puVar2 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
        *puVar2 = *puVar2 | (ushort)(1 << (uVar9 & 0x1f));
      }
    }
    else if (cStack_7f == '\x19') {
      cStack_7f = (**(code **)(_r_ip_funcs_p + 0x5c0))
                            (uVar9,abStack_60[0],*param_1,*(code **)(_r_ip_funcs_p + 0x5c0));
    }
    if ((cStack_7f != '(') && (cStack_7f != '=')) {
      if (cStack_7f != '\0') {
        (**(code **)(_r_ip_funcs_p + 0x5bc))
                  (uVar9,abStack_60[0],cStack_7f,0,*(code **)(_r_ip_funcs_p + 0x5bc));
      }
      goto _L26;
    }
    pcVar6 = *(code **)(_r_ip_funcs_p + 0x55c);
    cVar3 = cStack_7f;
  }
  else {
    cStack_7f = '\x19';
    if ((*(byte *)(iVar8 + 0x44) & 3) == 3) goto _L26;
    if ((*(byte *)(iVar8 + 0x44) & 3) == 0) goto _L30;
    pcVar6 = *(code **)(_r_ip_funcs_p + 0x55c);
_L66:
    cVar3 = '=';
  }
  (*pcVar6)(uVar9,cVar3,1,pcVar6);
_L26:
  (**(code **)(_r_ip_funcs_p + 0x104))
            (param_1[2],*(undefined4 *)(param_1 + 4),*(code **)(_r_ip_funcs_p + 0x104));
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar8 + 0x20) != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x610))(uVar9,*(code **)(_r_ip_funcs_p + 0x610));
  }
  return 0;
}

