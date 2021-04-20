/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> llc_llcp.o -> r_lld_llcp_rx_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_llcp_rx_ind_handler_hack(undefined2 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  undefined2 uStack_6e;
  byte abStack_6c [28];
  byte abStack_50 [48];
  
  iVar7 = *(int *)(&llc_env + (param_2 >> 8) * 4);
  uVar6 = param_2 >> 8 & 0xff;
  if (iVar7 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"llc_llcp.c",0xd9,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x5c4))(*(code **)(_r_ip_funcs_p + 0x5c4));
  if ((iVar7 == 0) || ((*(ushort *)(iVar7 + 0x42) & 0x40) != 0)) goto _L11;
  memcpy(abStack_6c,*(void **)(param_1 + 4),0x1b);
  abStack_50[0] = abStack_6c[0];
  if (abStack_6c[0] < 0x23) {
    iVar2 = (uint)abStack_6c[0] * 0xc + iVar1;
    if (*(ushort *)(iVar2 + 8) != (ushort)*(byte *)(param_1 + 1)) goto _L13;
    uStack_6e = 0x30;
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x18))
                      (abStack_50,abStack_6c,&uStack_6e,*(undefined4 *)(iVar2 + 4),
                       *(code **)(_r_modules_funcs_p + 0x18));
    if (iVar2 != 0) {
      iVar2 = 0x1e;
    }
    uVar3 = (uint)abStack_50[0];
    bVar4 = *(byte *)(iVar7 + 0x44) & 3;
    if (bVar4 != 2) {
      if (bVar4 == 3) {
        bVar4 = *(byte *)(iVar1 + uVar3 * 0xc + 10) & 8;
      }
      else {
        if (bVar4 == 1) {
          if ((*(byte *)(iVar1 + uVar3 * 0xc + 10) & 4) == 0) goto _L48;
          goto _L22;
        }
        bVar4 = *(byte *)(iVar1 + uVar3 * 0xc + 10) & 1;
      }
      if (bVar4 == 0) goto _L11;
    }
_L22:
    if (iVar2 == 0) {
      if (0x22 < uVar3) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (param_2,"llc_llcp.c",0x166,*(code **)(_r_plf_funcs_p + 0xc));
      }
      iVar2 = llcp_pdu_handler_pre(uVar6,abStack_50,*param_1);
      pcVar5 = (code *)llcp_pdu_handler_get(abStack_50[0]);
      if (iVar2 == 0) {
        if (pcVar5 == (code *)0x0) goto _L11;
        iVar2 = (*pcVar5)(uVar6,abStack_50,*param_1,pcVar5);
      }
      goto _L26;
    }
_L24:
    (**(code **)(_r_ip_funcs_p + 0x5bc))
              (uVar6,abStack_50[0],iVar2,0,*(code **)(_r_ip_funcs_p + 0x5bc));
  }
  else {
    bVar4 = *(byte *)(iVar7 + 0x44) & 3;
    if ((*(byte *)(iVar7 + 0x44) & 3) == 0) {
_L13:
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x5c0))(uVar6,*param_1,*(code **)(_r_ip_funcs_p + 0x5c0))
      ;
_L26:
      if ((iVar2 != 0x28) && (iVar2 != 0x3d)) {
        if (iVar2 == 0) goto _L11;
        goto _L24;
      }
      pcVar5 = *(code **)(_r_ip_funcs_p + 0x55c);
    }
    else {
      if (2 < bVar4) {
        if (bVar4 == 3) goto _L11;
        goto _L13;
      }
_L48:
      iVar2 = 0x3d;
      pcVar5 = *(code **)(_r_ip_funcs_p + 0x55c);
    }
    (*pcVar5)(uVar6,iVar2,1,pcVar5);
  }
_L11:
  (**(code **)(_r_ip_funcs_p + 0x104))
            (param_1[2],*(undefined4 *)(param_1 + 4),*(code **)(_r_ip_funcs_p + 0x104));
  (**(code **)(_r_ip_funcs_p + 0x610))(uVar6,*(code **)(_r_ip_funcs_p + 0x610));
  return 0;
}

