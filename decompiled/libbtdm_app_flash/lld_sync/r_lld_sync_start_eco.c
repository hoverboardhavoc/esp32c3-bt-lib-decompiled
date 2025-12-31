/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_lld_sync_start_eco(uint param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = r_lld_sync_start();
  iVar3 = r_sdk_config_get_opts();
  if (param_1 < *(byte *)(iVar3 + 0xd)) {
    if (*(int *)(&lld_sync_env + param_1 * 4) != 0) {
      iVar3 = r_emi_get_mem_addr_by_offset(0x400);
      uVar1 = *(ushort *)(iVar3 + param_1 * 0x5a);
      iVar3 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(param_1 * 0x5a + iVar3) = uVar1 & 0xffdf;
    }
  }
  r_ble_log_internal_x2
            (0x40050129,iVar2 << 0x18 | (uint)*(ushort *)(param_2 + 0xe) | param_1 << 0x10,
             *(undefined1 *)(param_2 + 0xb));
  return iVar2;
}

