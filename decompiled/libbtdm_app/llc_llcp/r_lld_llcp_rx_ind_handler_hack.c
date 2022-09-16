/*
 * Last changed at upstream commit 420ae1726dede6bbd4f3393744a8f3a252330b6a
 * https://github.com/espressif/esp32c3-bt-lib/commit/420ae1726dede6bbd4f3393744a8f3a252330b6a
 * Upstream date: 2022-09-16 21:21:40 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(421c2790)
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
  uint uVar8;
  undefined2 uStack_7e;
  byte abStack_7c [28];
  byte abStack_60 [60];
  
  uVar8 = param_2 >> 8;
  iVar7 = *(int *)(&llc_env + uVar8 * 4);
  uVar6 = uVar8 & 0xff;
  if (iVar7 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(uVar8,0,"llc_llcp.c",0xde,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x5c4))(*(code **)(_r_ip_funcs_p + 0x5c4));
  if ((iVar7 == 0) || ((*(ushort *)(iVar7 + 0x42) & 0x40) != 0)) goto _L11;
  memcpy(abStack_7c,*(void **)(param_1 + 4),0x1b);
  abStack_60[0] = abStack_7c[0];
  if (abStack_7c[0] < 0x23) {
    iVar2 = (uint)abStack_7c[0] * 0xc + iVar1;
    if (*(ushort *)(iVar2 + 8) != (ushort)*(byte *)(param_1 + 1)) goto _L13;
    uStack_7e = 0x30;
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x18))
                      (abStack_60,abStack_7c,&uStack_7e,*(undefined4 *)(iVar2 + 4),
                       *(code **)(_r_modules_funcs_p + 0x18));
    if (iVar2 != 0) {
      iVar2 = 0x1e;
    }
    uVar3 = (uint)abStack_60[0];
    bVar4 = *(byte *)(iVar7 + 0x44) & 3;
    if (bVar4 != 2) {
      if (bVar4 == 3) {
        bVar4 = *(byte *)(iVar1 + uVar3 * 0xc + 10) & 8;
      }
      else {
        if (bVar4 == 1) {
          if ((*(byte *)(iVar1 + uVar3 * 0xc + 10) & 4) == 0) goto _L47;
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
                  (param_2,"llc_llcp.c",0x16b,*(code **)(_r_plf_funcs_p + 0xc));
      }
      iVar2 = llcp_pdu_handler_pre(uVar6,abStack_60,*param_1);
      pcVar5 = (code *)llcp_pdu_handler_get(abStack_60[0]);
      if ((iVar2 == 0) && (pcVar5 != (code *)0x0)) {
        iVar2 = (*pcVar5)(uVar6,abStack_60,*param_1,pcVar5);
      }
      if ((abStack_60[0] == 6) && (iVar2 == 0)) {
        if ((*(ushort *)(iVar7 + 0x42) & 1) == 0) {
          enc_resp_recvd_slave = (byte)(1 << (uVar8 & 0x1f)) | enc_resp_recvd_slave;
        }
        goto _L11;
      }
      goto _L27;
    }
_L24:
    (**(code **)(_r_ip_funcs_p + 0x5bc))
              (uVar6,abStack_60[0],iVar2,0,*(code **)(_r_ip_funcs_p + 0x5bc));
  }
  else {
    bVar4 = *(byte *)(iVar7 + 0x44) & 3;
    if ((*(byte *)(iVar7 + 0x44) & 3) == 0) {
_L13:
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x5c0))(uVar6,*param_1,*(code **)(_r_ip_funcs_p + 0x5c0))
      ;
_L27:
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
_L47:
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

