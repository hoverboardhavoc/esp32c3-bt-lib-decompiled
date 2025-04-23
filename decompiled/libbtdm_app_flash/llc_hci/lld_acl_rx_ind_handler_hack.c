/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_hci.o -> lld_acl_rx_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_acl_rx_ind_handler_hack(ushort *param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  ushort *puVar4;
  int iVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  
  uVar8 = param_2 >> 8;
  iVar9 = *(int *)(&llc_env + uVar8 * 4);
  puVar4 = (ushort *)r_llc_enc_state_get();
  iVar5 = r_sdk_config_get_opts();
  if (((uVar8 < *(byte *)(iVar5 + 0xd)) && (iVar5 = *(int *)(&llc_env + uVar8 * 4), iVar5 != 0)) &&
     ((*(byte *)(iVar5 + 0x44) & 3) != 3)) {
    if (((*(byte *)(iVar9 + 0x44) & 3) == 0) || (((int)(uint)*puVar4 >> (uVar8 & 0x1f) & 1U) != 0))
    {
      puVar4 = (ushort *)r_ke_msg_alloc(0x1106,uVar8,0,0xc);
      uVar7 = 0x1000;
      if ((char)param_1[5] == '\x02') {
        uVar7 = 0x2000;
      }
      uVar1 = *param_1;
      uVar2 = param_1[4];
      *puVar4 = (ushort)(param_2 >> 8) | uVar7;
      puVar4[2] = uVar1;
      puVar4[1] = uVar2;
      uVar6 = r_emi_get_mem_addr_by_offset();
      *(undefined4 *)(puVar4 + 4) = uVar6;
      r_hci_send_2_host(puVar4);
      iVar5 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar5 + 0x20) != '\0') {
        r_llc_le_ping_restart(uVar8);
      }
      if (ble_acl_data_rx_cb == (code *)0x0) {
        return 0;
      }
      cVar3 = (char)param_1[5];
      if (cVar3 != '\x02') {
        cVar3 = '\x01';
      }
      (*ble_acl_data_rx_cb)(cVar3,*(undefined4 *)(puVar4 + 4),param_1[4]);
      return 0;
    }
    r_llc_disconnect(uVar8,0x3d,1);
  }
  r_ble_util_buf_rx_free(*param_1,*(undefined4 *)(param_1 + 2));
  return 0;
}

