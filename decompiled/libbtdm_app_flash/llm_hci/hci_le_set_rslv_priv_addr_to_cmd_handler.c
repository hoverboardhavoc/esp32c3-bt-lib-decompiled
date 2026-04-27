/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_set_rslv_priv_addr_to_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_rslv_priv_addr_to_cmd_handler(ushort *param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *param_1;
  if ((uVar1 - 1 & 0xffff) < 0xa1b8) {
    *(ushort *)(_p_llm_env + 0xc4) = uVar1;
    iVar2 = r_ke_timer_active(6,0);
    uVar3 = 0;
    if (iVar2 != 0) {
      r_ke_timer_clear(6,0);
      r_ke_timer_set(6,0,(uint)*(ushort *)(_p_llm_env + 0xc4) * 100);
      uVar3 = 0;
    }
  }
  else {
    r_ble_log_internal_x1(0x802e01d6,uVar1 | 0x120000);
    uVar3 = 0x12;
  }
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

