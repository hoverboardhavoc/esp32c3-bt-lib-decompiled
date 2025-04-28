/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_lld_llcp_rx_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_llcp_rx_ind_handler(undefined2 *param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  undefined2 uStack_6e;
  byte abStack_6c [28];
  byte local_50 [52];
  
  uVar6 = param_2 >> 8;
  iVar5 = *(int *)(&llc_env + uVar6 * 4);
  if (iVar5 == 0) {
    r_assert_param(uVar6,0,"llc_llcp.c",0xfd);
    goto _L92;
  }
  if ((*(ushort *)(iVar5 + 0x42) & 0x40) != 0) goto _L92;
  memcpy(abStack_6c,*(void **)(param_1 + 4),0x1b);
  local_50[0] = abStack_6c[0];
  iVar2 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar2 + 0x28) & 0x20) != 0) &&
     (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 2)) {
    r_ble_log_internal_hex(0x20c3001d,*(undefined1 *)(param_1 + 1),abStack_6c);
  }
  if (local_50[0] < 0x23) {
    iVar2 = (uint)local_50[0] * 0xc;
    if (*(ushort *)(llcp_pdu_handler + iVar2 + 8) != (ushort)*(byte *)(param_1 + 1)) {
_L99:
      llc_ll_unknown_rsp_pdu_send(uVar6);
      goto _L92;
    }
    uStack_6e = 0x30;
    iVar2 = r_co_util_unpack(local_50,abStack_6c,&uStack_6e,
                             *(undefined4 *)(llcp_pdu_handler + iVar2 + 4));
    if (iVar2 != 0) {
      iVar2 = 0x1e;
    }
    uVar3 = (uint)local_50[0];
    bVar4 = *(byte *)(iVar5 + 0x44) & 3;
    if (bVar4 != 2) {
      if (bVar4 == 3) {
        bVar4 = llcp_pdu_handler[uVar3 * 0xc + 10] & 8;
      }
      else {
        if (bVar4 == 1) {
          if ((llcp_pdu_handler[uVar3 * 0xc + 10] & 4) == 0) goto _L133;
          goto _L102;
        }
        bVar4 = llcp_pdu_handler[uVar3 * 0xc + 10] & 1;
      }
      if (bVar4 == 0) goto _L92;
    }
_L102:
    if (iVar2 == 0) {
      if (0x22 < uVar3) {
        r_assert_param(param_2,"llc_llcp.c",0x18b);
      }
      iVar2 = r_llc_llcp_pdu_handler_pre(uVar6,local_50,*param_1);
      if ((iVar2 == 0) &&
         (pcVar1 = (code *)r_llc_llcp_pdu_handler_get_overwrite(local_50[0]), pcVar1 != (code *)0x0)
         ) {
        iVar2 = (*pcVar1)(uVar6,local_50,*param_1,pcVar1);
      }
      if ((local_50[0] == 6) && (iVar2 == 0)) {
        if ((*(ushort *)(iVar5 + 0x42) & 1) == 0) {
          llc_enc_state = llc_enc_state | (ushort)(1 << (uVar6 & 0x1f));
        }
        goto _L92;
      }
      if ((iVar2 == 0x28) || (iVar2 == 0x3d)) goto _L134;
      if (iVar2 == 0) goto _L92;
    }
    else {
      iVar2 = 0x1e;
    }
    r_llc_ll_reject_ind_pdu_send(uVar6,local_50[0],iVar2,0);
  }
  else {
    if ((*(byte *)(iVar5 + 0x44) & 3) == 3) goto _L92;
    if ((*(byte *)(iVar5 + 0x44) & 3) == 0) goto _L99;
_L133:
    iVar2 = 0x3d;
_L134:
    r_llc_disconnect(uVar6,iVar2,1);
  }
_L92:
  r_ble_util_buf_rx_free(param_1[2],*(undefined4 *)(param_1 + 4));
  iVar5 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar5 + 0x20) != '\0') {
    r_llc_le_ping_restart(uVar6);
  }
  return 0;
}

