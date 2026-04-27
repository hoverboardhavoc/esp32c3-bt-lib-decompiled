/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_hci.o -> lld_acl_rx_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_acl_rx_ind_handler_hack(ushort *param_1,uint param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  char cVar4;
  ushort *puVar5;
  int iVar6;
  undefined4 uVar7;
  ushort uVar8;
  int iVar9;
  
  uVar3 = param_2 >> 8;
  iVar9 = *(int *)(&llc_env + uVar3 * 4);
  puVar5 = (ushort *)r_llc_enc_state_get();
  iVar6 = r_sdk_config_get_opts();
  if (((uVar3 < *(byte *)(iVar6 + 0xd)) && (iVar6 = *(int *)(&llc_env + uVar3 * 4), iVar6 != 0)) &&
     ((*(byte *)(iVar6 + 0x44) & 3) != 3)) {
    bVar1 = *(byte *)(iVar9 + 0x44);
    if (((bVar1 & 3) == 0) || (((int)(uint)*puVar5 >> (uVar3 & 0x1f) & 1U) != 0)) {
      puVar5 = (ushort *)r_ke_msg_alloc(0x1106,uVar3,0,0xc);
      uVar8 = 0x2000;
      if ((char)param_1[5] != '\x02') {
        uVar8 = 0x1000;
      }
      uVar2 = *param_1;
      *puVar5 = (ushort)(param_2 >> 8) & 0xfff | uVar8;
      uVar8 = param_1[4];
      puVar5[2] = uVar2;
      puVar5[1] = uVar8;
      uVar7 = r_emi_get_mem_addr_by_offset();
      *(undefined4 *)(puVar5 + 4) = uVar7;
      r_hci_send_2_host(puVar5);
      iVar6 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar6 + 0x20) != '\0') {
        r_llc_le_ping_restart_hack(uVar3);
      }
      if (ble_acl_data_rx_cb == (code *)0x0) {
        return 0;
      }
      cVar4 = (char)param_1[5];
      if (cVar4 != '\x02') {
        cVar4 = '\x01';
      }
      (*ble_acl_data_rx_cb)(cVar4,*(undefined4 *)(puVar5 + 4),param_1[4]);
      return 0;
    }
    r_ble_log_internal_x1(0x808f00af,(uint)bVar1 << 8 | uVar3);
    r_llc_disconnect(uVar3,0x3d,1);
  }
  else {
    r_ble_log_internal_x1(0x608f00ae,(uint)param_1[4] << 8 | uVar3);
  }
  r_ble_util_buf_rx_free(*param_1,*(undefined4 *)(param_1 + 2));
  return 0;
}

