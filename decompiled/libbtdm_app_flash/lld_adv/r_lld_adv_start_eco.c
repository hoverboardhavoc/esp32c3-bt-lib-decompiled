/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_lld_adv_start_eco(uint param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  if (g_ble_ext_config != '\0') {
    DAT_00016568 = 0;
  }
  llm_ext_adv_get_own_addr(param_1,*(undefined1 *)(param_2 + 0x1e),param_2);
  iVar2 = r_lld_adv_start(param_1,param_2);
  r_lld_adv_start_hook_part_0(param_1,param_2);
  iVar3 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar3 + 0x28) & 4) != 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar3 + 0x2c) < 3) {
      r_ble_log_internal_x1
                (0x40000000,iVar2 << 8 | (uint)*(ushort *)(param_2 + 0x18) << 0x10 | param_1);
    }
  }
  iVar3 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar3 + 0x28) & 4) != 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar3 + 0x2c) < 3) {
      iVar3 = r_emi_get_mem_addr_by_offset(0x400);
      uVar1 = *(undefined2 *)(param_1 * 0x5a + 0x2c + iVar3);
      iVar3 = r_emi_get_mem_addr_by_offset(0x400);
      r_ble_log_internal_x2
                (0x40000005,param_1,CONCAT22(uVar1,*(undefined2 *)(param_1 * 0x5a + 0x14 + iVar3)));
    }
  }
  return iVar2;
}

