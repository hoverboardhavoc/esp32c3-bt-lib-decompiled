/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_scan.o -> ble_ll_scan_channel_setting
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ble_ll_scan_channel_setting(int param_1)

{
  int iVar1;
  ushort uVar2;
  
  iVar1 = r_ble_ll_qa_config_get();
  uVar2 = 0;
  if ((param_1 - 0x25U & 0xffff) < 3) {
    uVar2 = (ushort)*(byte *)(param_1 + 0x14aa7);
  }
  *(ushort *)(iVar1 + 0x18) = uVar2;
  return;
}

