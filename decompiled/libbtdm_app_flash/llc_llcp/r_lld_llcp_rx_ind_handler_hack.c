/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_lld_llcp_rx_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_llcp_rx_ind_handler_hack(undefined2 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined2 uStack_6e;
  byte abStack_6c [28];
  byte local_50 [48];
  
  uVar6 = param_2 >> 8;
  iVar7 = *(int *)(&llc_env + uVar6 * 4);
  if (iVar7 == 0) {
    r_assert_param(uVar6,0,"llc_llcp.c",0xfe);
    goto _L87;
  }
  if ((*(ushort *)(iVar7 + 0x42) & 0x40) != 0) goto _L87;
  memcpy(abStack_6c,*(void **)(param_1 + 4),0x1b);
  local_50[0] = abStack_6c[0];
  r_ble_log_internal_x1(0x408f009e,(uint)abStack_6c[0] << 8 | uVar6);
  r_ble_log_internal_hex(0x408f009f,*(undefined1 *)(param_1 + 1),abStack_6c);
  if (local_50[0] < 0x23) {
    iVar1 = (uint)local_50[0] * 0xc;
    iVar2 = 0x19;
    if (*(ushort *)(llcp_pdu_handler + iVar1 + 8) == (ushort)*(byte *)(param_1 + 1)) {
      uStack_6e = 0x30;
      iVar2 = r_co_util_unpack(local_50,abStack_6c,&uStack_6e,
                               *(undefined4 *)(llcp_pdu_handler + iVar1 + 4));
      if (iVar2 != 0) {
        iVar2 = 0x1e;
      }
      bVar4 = *(byte *)(iVar7 + 0x44) & 3;
      if (bVar4 != 2) {
        uVar5 = (uint)local_50[0];
        if (bVar4 == 3) {
          uVar5 = (byte)llcp_pdu_handler[uVar5 * 0xc + 10] & 8;
        }
        else {
          if (bVar4 == 1) {
            bVar4 = llcp_pdu_handler[uVar5 * 0xc + 10] & 4;
            goto joined_r0x00010692;
          }
          uVar5 = (byte)llcp_pdu_handler[uVar5 * 0xc + 10] & 1;
        }
        if (uVar5 == 0) goto _L89;
      }
    }
_L90:
    iVar1 = r_sdk_config_get_opts_ext();
    if ((*(char *)(iVar1 + 0x18) == '\0') && (0x15 < local_50[0])) {
_L99:
      llc_ll_unknown_rsp_pdu_send(uVar6);
      goto _L87;
    }
    if (iVar2 == 0) {
      if (0x22 < local_50[0]) {
        r_assert_param(param_2,"llc_llcp.c",0x192);
      }
      iVar2 = r_llc_llcp_pdu_handler_pre(uVar6,local_50,*param_1);
      if ((iVar2 == 0) &&
         (pcVar3 = (code *)r_llc_llcp_pdu_handler_get_overwrite(local_50[0]), pcVar3 != (code *)0x0)
         ) {
        iVar2 = (*pcVar3)(uVar6,local_50,*param_1,pcVar3);
      }
      if ((local_50[0] == 6) && (iVar2 == 0)) {
        if ((*(ushort *)(iVar7 + 0x42) & 1) == 0) {
          llc_enc_state = llc_enc_state | (ushort)(1 << (uVar6 & 0x1f));
        }
        goto _L87;
      }
      if ((iVar2 != 0x28) && (iVar2 != 0x3d)) {
        if (iVar2 == 0) goto _L87;
        goto _L105;
      }
      r_llc_disconnect(uVar6,iVar2,1);
    }
    else {
      if (iVar2 == 0x19) goto _L99;
      iVar2 = 0x1e;
_L105:
      r_llc_ll_reject_ind_pdu_send(uVar6,local_50[0],iVar2,0);
    }
    uVar5 = 1;
  }
  else {
    bVar4 = *(byte *)(iVar7 + 0x44) & 3;
    if ((*(byte *)(iVar7 + 0x44) & 3) == 3) {
      uVar5 = 0;
      iVar2 = 0x19;
    }
    else {
      iVar2 = 0x19;
joined_r0x00010692:
      if (bVar4 != 0) goto _L90;
      r_llc_disconnect(uVar6,0x3d,1);
      uVar5 = 0;
    }
  }
_L89:
  r_ble_log_internal_x2
            (0x808f00a0,(uint)local_50[0] << 0x18 | uVar6 | uVar5 << 8 | iVar2 << 0x10,
             *(undefined1 *)(param_1 + 1));
_L87:
  r_ble_util_buf_rx_free(param_1[2],*(undefined4 *)(param_1 + 4));
  iVar7 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar7 + 0x20) != '\0') {
    r_llc_le_ping_restart_hack(uVar6);
  }
  return 0;
}

