/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_lld_llcp_rx_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_llcp_rx_ind_handler_hack(undefined2 *param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined2 uStack_6e;
  byte abStack_6c [28];
  byte local_50 [48];
  
  uVar7 = param_2 >> 8;
  iVar6 = *(int *)(&llc_env + uVar7 * 4);
  if (iVar6 == 0) {
    r_assert_param(uVar7,0,"llc_llcp.c",0xfe);
    goto _L92;
  }
  if ((*(ushort *)(iVar6 + 0x42) & 0x40) != 0) goto _L92;
  memcpy(abStack_6c,*(void **)(param_1 + 4),0x1b);
  local_50[0] = abStack_6c[0];
  iVar2 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar2 + 0x28) & 0x20) != 0) &&
     (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 2)) {
    r_ble_log_internal_hex(0x20c3001d,*(undefined1 *)(param_1 + 1),abStack_6c);
  }
  if (0x22 < local_50[0]) {
    bVar4 = *(byte *)(iVar6 + 0x44) & 3;
    if ((*(byte *)(iVar6 + 0x44) & 3) == 3) goto _L92;
    iVar2 = 0x19;
joined_r0x000106b2:
    if (bVar4 != 0) goto _L99;
    iVar3 = 0x3d;
_L140:
    r_llc_disconnect(uVar7,iVar3,1);
    goto _L92;
  }
  iVar3 = (uint)local_50[0] * 0xc;
  iVar2 = 0x19;
  if (*(ushort *)(llcp_pdu_handler + iVar3 + 8) == (ushort)*(byte *)(param_1 + 1)) {
    uStack_6e = 0x30;
    iVar2 = r_co_util_unpack(local_50,abStack_6c,&uStack_6e,
                             *(undefined4 *)(llcp_pdu_handler + iVar3 + 4));
    if (iVar2 != 0) {
      iVar2 = 0x1e;
    }
    bVar4 = *(byte *)(iVar6 + 0x44) & 3;
    if (bVar4 != 2) {
      uVar5 = (uint)local_50[0];
      if (bVar4 == 3) {
        bVar4 = llcp_pdu_handler[uVar5 * 0xc + 10] & 8;
      }
      else {
        if (bVar4 == 1) {
          bVar4 = llcp_pdu_handler[uVar5 * 0xc + 10] & 4;
          goto joined_r0x000106b2;
        }
        bVar4 = llcp_pdu_handler[uVar5 * 0xc + 10] & 1;
      }
      if (bVar4 == 0) goto _L92;
    }
  }
_L99:
  iVar3 = r_sdk_config_get_opts_ext();
  if ((*(char *)(iVar3 + 0x18) == '\0') && (0x15 < local_50[0])) {
_L109:
    llc_ll_unknown_rsp_pdu_send(uVar7);
  }
  else {
    if (iVar2 == 0) {
      if (0x22 < local_50[0]) {
        r_assert_param(param_2,"llc_llcp.c",0x191);
      }
      iVar3 = r_llc_llcp_pdu_handler_pre(uVar7,local_50,*param_1);
      if ((iVar3 == 0) &&
         (pcVar1 = (code *)r_llc_llcp_pdu_handler_get_overwrite(local_50[0]), pcVar1 != (code *)0x0)
         ) {
        iVar3 = (*pcVar1)(uVar7,local_50,*param_1,pcVar1);
      }
      if ((local_50[0] == 6) && (iVar3 == 0)) {
        if ((*(ushort *)(iVar6 + 0x42) & 1) == 0) {
          llc_enc_state = llc_enc_state | (ushort)(1 << (uVar7 & 0x1f));
        }
        goto _L92;
      }
      if ((iVar3 == 0x28) || (iVar3 == 0x3d)) goto _L140;
      if (iVar3 == 0) goto _L92;
    }
    else {
      iVar3 = 0x1e;
      if (iVar2 == 0x19) goto _L109;
    }
    r_llc_ll_reject_ind_pdu_send(uVar7,local_50[0],iVar3,0);
  }
_L92:
  r_ble_util_buf_rx_free(param_1[2],*(undefined4 *)(param_1 + 4));
  iVar6 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar6 + 0x20) != '\0') {
    r_llc_le_ping_restart_hack(uVar7);
  }
  return 0;
}

