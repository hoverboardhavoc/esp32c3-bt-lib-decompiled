/*
 * Last changed at upstream commit 0caae2bd70a999ac8a1c07330f7168e185db81ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/0caae2bd70a999ac8a1c07330f7168e185db81ba
 * Upstream date: 2024-01-31 19:37:46 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(91980c2)
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
  char cStack_6f;
  undefined2 uStack_6e;
  byte abStack_6c [28];
  byte abStack_50 [48];
  
  uVar10 = param_2 >> 8;
  iVar9 = *(int *)(&llc_env + uVar10 * 4);
  uVar1 = uVar10 & 0xff;
  if (iVar9 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(uVar10,0,"llc_llcp.c",0xf1,*(code **)(_r_plf_funcs_p + 0xc))
    ;
  }
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x5c4))(*(code **)(_r_ip_funcs_p + 0x5c4));
  if ((iVar9 == 0) || ((*(ushort *)(iVar9 + 0x42) & 0x40) != 0)) goto _L16;
  memcpy(abStack_6c,*(void **)(param_1 + 4),0x1b);
  abStack_50[0] = abStack_6c[0];
  if (abStack_6c[0] < 0x23) {
    iVar8 = (uint)abStack_6c[0] * 0xc + iVar2;
    if (*(ushort *)(iVar8 + 8) == (ushort)*(byte *)(param_1 + 1)) {
      uStack_6e = 0x30;
      iVar8 = (**(code **)(_r_modules_funcs_p + 0x18))
                        (abStack_50,abStack_6c,&uStack_6e,*(undefined4 *)(iVar8 + 4),
                         *(code **)(_r_modules_funcs_p + 0x18));
      if (iVar8 == 0) {
        cStack_6f = '\0';
      }
      else {
        cStack_6f = '\x1e';
      }
      bVar7 = *(byte *)(iVar9 + 0x44) & 3;
      if (bVar7 != 2) {
        uVar5 = (uint)abStack_50[0];
        if (bVar7 == 3) {
          bVar7 = *(byte *)(uVar5 * 0xc + iVar2 + 10) & 8;
        }
        else {
          if (bVar7 == 1) {
            if ((*(byte *)(uVar5 * 0xc + iVar2 + 10) & 4) == 0) goto _L54;
            goto _L18;
          }
          bVar7 = *(byte *)(uVar5 * 0xc + iVar2 + 10) & 1;
        }
        if (bVar7 == 0) goto _L16;
      }
    }
    else {
      cStack_6f = '\x19';
    }
_L18:
    if (cStack_6f == '\0') {
      if (0x22 < abStack_50[0]) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (param_2,"llc_llcp.c",0x17e,*(code **)(_r_plf_funcs_p + 0xc));
      }
      cStack_6f = (**(code **)(_r_ip_funcs_p + 0x8ec))
                            (uVar1,abStack_50,*param_1,*(code **)(_r_ip_funcs_p + 0x8ec));
      pcVar3 = (code *)(**(code **)(_r_ip_funcs_p + 0x8e8))
                                 (abStack_50[0],*(code **)(_r_ip_funcs_p + 0x8e8));
      if ((cStack_6f == '\0') && (pcVar3 != (code *)0x0)) {
        cStack_6f = (*pcVar3)(uVar1,abStack_50,*param_1,pcVar3);
        (**(code **)(_r_ip_funcs_p + 0x8f0))
                  (&cStack_6f,uVar1,abStack_50,*param_1,*(code **)(_r_ip_funcs_p + 0x8f0));
      }
      if (((abStack_50[0] == 6) && (cStack_6f == '\0')) && ((*(ushort *)(iVar9 + 0x42) & 1) == 0)) {
        puVar4 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
        *puVar4 = (ushort)(1 << (uVar10 & 0x1f)) | *puVar4;
      }
    }
    else if (cStack_6f == '\x19') {
      cStack_6f = (**(code **)(_r_ip_funcs_p + 0x5c0))
                            (uVar1,abStack_50[0],*param_1,*(code **)(_r_ip_funcs_p + 0x5c0));
    }
    if ((cStack_6f != '(') && (cStack_6f != '=')) {
      if (cStack_6f != '\0') {
        (**(code **)(_r_ip_funcs_p + 0x5bc))
                  (uVar1,abStack_50[0],cStack_6f,0,*(code **)(_r_ip_funcs_p + 0x5bc));
      }
      goto _L16;
    }
    pcVar3 = *(code **)(_r_ip_funcs_p + 0x55c);
    cVar6 = cStack_6f;
  }
  else {
    cStack_6f = '\x19';
    bVar7 = *(byte *)(iVar9 + 0x44) & 3;
    if ((*(byte *)(iVar9 + 0x44) & 3) == 0) goto _L18;
    if (2 < bVar7) {
      if (bVar7 == 3) goto _L16;
      goto _L18;
    }
_L54:
    cVar6 = '=';
    pcVar3 = *(code **)(_r_ip_funcs_p + 0x55c);
  }
  (*pcVar3)(uVar1,cVar6,1,pcVar3);
_L16:
  (**(code **)(_r_ip_funcs_p + 0x104))
            (param_1[2],*(undefined4 *)(param_1 + 4),*(code **)(_r_ip_funcs_p + 0x104));
  (**(code **)(_r_ip_funcs_p + 0x610))(uVar1,*(code **)(_r_ip_funcs_p + 0x610));
  return 0;
}

