/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> arch_main.o -> esp_ble_clear_all_rxerr_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_ble_clear_all_rxerr_cnt(undefined1 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = llm_hdl_to_id(param_1);
  iVar2 = r_sdk_config_get_opts();
  uVar3 = 1;
  if (uVar1 < *(byte *)(iVar2 + 0xd)) {
    uVar3 = lld_le_pkt_err_clear(uVar1);
  }
  return uVar3;
}

