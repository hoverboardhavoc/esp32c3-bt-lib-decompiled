/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_sync_start_eco(uint param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 0x80) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 3) {
      r_ble_log_internal_x2
                (0x40020000,(uint)*(byte *)(param_2 + 0xb) << 8 | param_1,
                 *(undefined2 *)(param_2 + 0xe));
    }
  }
  uVar3 = r_lld_sync_start(param_1,param_2);
  iVar2 = r_sdk_config_get_opts();
  if (param_1 < *(byte *)(iVar2 + 0xd)) {
    if (*(int *)(&lld_sync_env + param_1 * 4) != 0) {
      iVar2 = r_emi_get_mem_addr_by_offset(0x400);
      uVar1 = *(ushort *)(iVar2 + param_1 * 0x5a);
      iVar2 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(param_1 * 0x5a + iVar2) = uVar1 & 0xffdf;
    }
  }
  return uVar3;
}

