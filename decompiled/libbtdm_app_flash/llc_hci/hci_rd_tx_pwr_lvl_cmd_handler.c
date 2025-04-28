/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_hci.o -> hci_rd_tx_pwr_lvl_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_rd_tx_pwr_lvl_cmd_handler(uint param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,*param_2,0xc2d,6);
  iVar3 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    *puVar2 = 0;
    if (*(char *)(param_2 + 1) == '\0') {
      uVar1 = r_lld_con_current_tx_power_get(param_1,1);
      goto _L4;
    }
    if (*(char *)(param_2 + 1) == '\x01') {
      uVar1 = (*_r_ble_util_buf_rx_free)(DAT_00011045,1,_r_ble_util_buf_rx_free);
      goto _L4;
    }
    uVar1 = 0x12;
  }
  else {
    uVar1 = 0xc;
  }
  *puVar2 = uVar1;
  uVar1 = 0;
_L4:
  puVar2[4] = uVar1;
  *(undefined2 *)(puVar2 + 2) = *param_2;
  r_hci_send_2_host(puVar2);
  return 0;
}

