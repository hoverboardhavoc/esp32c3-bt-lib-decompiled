/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> llc_llcp.o -> r_lld_llcp_rx_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_llcp_rx_ind_handler(undefined2 *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  ushort *puVar4;
  uint uVar5;
  char cVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  char cStack_7f;
  undefined2 uStack_7e;
  byte abStack_7c [28];
  byte abStack_60 [60];
  
  uVar10 = param_2 >> 8;
  iVar9 = *(int *)(&llc_env + uVar10 * 4);
  uVar1 = uVar10 & 0xff;
  if (iVar9 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(uVar10,0,"llc_llcp.c",0xfd,*(code **)(_r_plf_funcs_p + 0xc))
    ;
  }
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x5c4))(*(code **)(_r_ip_funcs_p + 0x5c4));
  if ((iVar9 == 0) || ((*(ushort *)(iVar9 + 0x42) & 0x40) != 0)) goto _L26;
  memcpy(abStack_7c,*(void **)(param_1 + 4),0x1b);
  abStack_60[0] = abStack_7c[0];
  if (abStack_7c[0] < 0x23) {
    iVar8 = (uint)abStack_7c[0] * 0xc + iVar2;
    if (*(ushort *)(iVar8 + 8) == (ushort)*(byte *)(param_1 + 1)) {
      uStack_7e = 0x30;
      iVar8 = (**(code **)(_r_modules_funcs_p + 0x18))
                        (abStack_60,abStack_7c,&uStack_7e,*(undefined4 *)(iVar8 + 4),
                         *(code **)(_r_modules_funcs_p + 0x18));
      if (iVar8 == 0) {
        cStack_7f = '\0';
      }
      else {
        cStack_7f = '\x1e';
      }
      bVar7 = *(byte *)(iVar9 + 0x44) & 3;
      if (bVar7 != 2) {
        uVar5 = (uint)abStack_60[0];
        if (bVar7 == 3) {
          bVar7 = *(byte *)(uVar5 * 0xc + iVar2 + 10) & 8;
        }
        else {
          if (bVar7 == 1) {
            if ((*(byte *)(uVar5 * 0xc + iVar2 + 10) & 4) == 0) goto _L68;
            goto _L28;
          }
          bVar7 = *(byte *)(uVar5 * 0xc + iVar2 + 10) & 1;
        }
        if (bVar7 == 0) goto _L26;
      }
    }
    else {
      cStack_7f = '\x19';
    }
_L28:
    if (cStack_7f == '\0') {
      if (0x22 < abStack_60[0]) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (param_2,"llc_llcp.c",0x18b,*(code **)(_r_plf_funcs_p + 0xc));
      }
      cStack_7f = (**(code **)(_r_ip_funcs_p + 0x8ec))
                            (uVar1,abStack_60,*param_1,*(code **)(_r_ip_funcs_p + 0x8ec));
      pcVar3 = (code *)(**(code **)(_r_ip_funcs_p + 0x8e8))
                                 (abStack_60[0],*(code **)(_r_ip_funcs_p + 0x8e8));
      if ((cStack_7f == '\0') && (pcVar3 != (code *)0x0)) {
        cStack_7f = (*pcVar3)(uVar1,abStack_60,*param_1,pcVar3);
        (**(code **)(_r_ip_funcs_p + 0x8f0))
                  (&cStack_7f,uVar1,abStack_60,*param_1,*(code **)(_r_ip_funcs_p + 0x8f0));
      }
      if (((abStack_60[0] == 6) && (cStack_7f == '\0')) && ((*(ushort *)(iVar9 + 0x42) & 1) == 0)) {
        puVar4 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
        *puVar4 = (ushort)(1 << (uVar10 & 0x1f)) | *puVar4;
      }
    }
    else if (cStack_7f == '\x19') {
      cStack_7f = (**(code **)(_r_ip_funcs_p + 0x5c0))
                            (uVar1,abStack_60[0],*param_1,*(code **)(_r_ip_funcs_p + 0x5c0));
    }
    if ((cStack_7f != '(') && (cStack_7f != '=')) {
      if (cStack_7f != '\0') {
        (**(code **)(_r_ip_funcs_p + 0x5bc))
                  (uVar1,abStack_60[0],cStack_7f,0,*(code **)(_r_ip_funcs_p + 0x5bc));
      }
      goto _L26;
    }
    pcVar3 = *(code **)(_r_ip_funcs_p + 0x55c);
    cVar6 = cStack_7f;
  }
  else {
    cStack_7f = '\x19';
    bVar7 = *(byte *)(iVar9 + 0x44) & 3;
    if ((*(byte *)(iVar9 + 0x44) & 3) == 0) goto _L28;
    if (2 < bVar7) {
      if (bVar7 == 3) goto _L26;
      goto _L28;
    }
_L68:
    cVar6 = '=';
    pcVar3 = *(code **)(_r_ip_funcs_p + 0x55c);
  }
  (*pcVar3)(uVar1,cVar6,1,pcVar3);
_L26:
  (**(code **)(_r_ip_funcs_p + 0x104))
            (param_1[2],*(undefined4 *)(param_1 + 4),*(code **)(_r_ip_funcs_p + 0x104));
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar9 + 0x20) != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x610))(uVar1,*(code **)(_r_ip_funcs_p + 0x610));
  }
  return 0;
}

