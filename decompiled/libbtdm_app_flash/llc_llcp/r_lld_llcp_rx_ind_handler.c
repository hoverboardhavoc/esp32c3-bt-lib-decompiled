/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_lld_llcp_rx_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_llcp_rx_ind_handler(undefined2 *param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined2 uStack_6e;
  byte abStack_6c [28];
  byte local_50 [48];
  
  uVar7 = param_2 >> 8;
  iVar6 = *(int *)(&llc_env + uVar7 * 4);
  uVar1 = uVar7 & 0xff;
  if (iVar6 == 0) {
    r_assert_param(uVar7,0,"llc_llcp.c",0xfd);
    goto _L75;
  }
  if ((*(ushort *)(iVar6 + 0x42) & 0x40) != 0) goto _L75;
  memcpy(abStack_6c,*(void **)(param_1 + 4),0x1b);
  local_50[0] = abStack_6c[0];
  uVar4 = (uint)abStack_6c[0];
  if (uVar4 < 0x23) {
    if (*(ushort *)(&DAT_0001077c + uVar4 * 0xc) == (ushort)*(byte *)(param_1 + 1)) {
      uStack_6e = 0x30;
      iVar3 = r_co_util_unpack(local_50,abStack_6c,&uStack_6e,(&PTR__LC1_00010778)[uVar4 * 3]);
      if (iVar3 != 0) {
        iVar3 = 0x1e;
      }
      uVar4 = (uint)local_50[0];
      bVar5 = *(byte *)(iVar6 + 0x44) & 3;
      if (bVar5 != 2) {
        if (bVar5 == 3) {
          bVar5 = (&DAT_0001077e)[uVar4 * 0xc] & 8;
        }
        else {
          if (bVar5 == 1) {
            if (((&DAT_0001077e)[uVar4 * 0xc] & 4) == 0) goto _L115;
            goto _L86;
          }
          bVar5 = (&DAT_0001077e)[uVar4 * 0xc] & 1;
        }
        if (bVar5 == 0) goto _L75;
      }
_L86:
      if (iVar3 == 0) {
        if (0x22 < uVar4) {
          r_assert_param(param_2,"llc_llcp.c",0x18a);
        }
        iVar3 = r_llc_llcp_pdu_handler_pre(uVar1,local_50,*param_1);
        if ((iVar3 == 0) &&
           (pcVar2 = (code *)r_llc_llcp_pdu_handler_get_overwrite(local_50[0]),
           pcVar2 != (code *)0x0)) {
          iVar3 = (*pcVar2)(uVar1,local_50,*param_1,pcVar2);
        }
        if ((local_50[0] == 6) && (iVar3 == 0)) {
          if ((*(ushort *)(iVar6 + 0x42) & 1) == 0) {
            llc_enc_state = (ushort)(1 << (uVar7 & 0x1f)) | llc_enc_state;
          }
          goto _L75;
        }
        if ((iVar3 == 0x28) || (iVar3 == 0x3d)) goto _L116;
        if (iVar3 == 0) goto _L75;
      }
      r_llc_ll_reject_ind_pdu_send(uVar1,local_50[0],iVar3,0);
      goto _L75;
    }
  }
  else {
    bVar5 = *(byte *)(iVar6 + 0x44) & 3;
    if ((*(byte *)(iVar6 + 0x44) & 3) != 0) {
      if (bVar5 < 3) {
_L115:
        iVar3 = 0x3d;
_L116:
        r_llc_disconnect(uVar1,iVar3,1);
        goto _L75;
      }
      if (bVar5 == 3) goto _L75;
    }
  }
  llc_ll_unknown_rsp_pdu_send(uVar1);
_L75:
  r_ble_util_buf_rx_free(param_1[2],*(undefined4 *)(param_1 + 4));
  iVar6 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar6 + 0x20) != '\0') {
    r_llc_le_ping_restart(uVar1);
  }
  return 0;
}

