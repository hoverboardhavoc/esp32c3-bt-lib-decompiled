/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_lld_adv_start_eco(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  
  if (g_ble_ext_config != '\0') {
    DAT_000165a4 = 0;
  }
  llm_ext_adv_get_own_addr(param_1,*(undefined1 *)(param_2 + 0x1e),param_2);
  iVar3 = r_lld_adv_start(param_1,param_2);
  r_lld_adv_start_hook_part_0(param_1,param_2);
  uVar1 = *(undefined2 *)(param_2 + 0x18);
  iVar4 = r_emi_get_mem_addr_by_offset(0x400);
  uVar2 = *(undefined2 *)(param_1 * 0x5a + 0x14 + iVar4);
  iVar4 = r_emi_get_mem_addr_by_offset(0x400);
  r_ble_log_internal_x2
            (0x4000005b,CONCAT22(uVar2,uVar1),
             (uint)*(ushort *)(param_1 * 0x5a + 0x2c + iVar4) | param_1 << 0x10 | iVar3 << 0x18);
  return iVar3;
}

