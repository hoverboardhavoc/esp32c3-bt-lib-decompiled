/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_len_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_tx_len_update(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar2 = (((param_3 - rwip_prog_delay) * 0x271 - 0x753 >> 1) - 0x96) -
          (uint)*(ushort *)(&fixed_tx_time + (uint)*(byte *)(iVar1 + 0x93) * 2);
  if (*(ushort *)(iVar1 + 0x88) < uVar2) {
    uVar2 = (uint)*(ushort *)(iVar1 + 0x88);
  }
  uVar2 = uVar2 - *(ushort *)(&fixed_tx_time + param_2 * 2);
  if ((*(ushort *)(iVar1 + 0x84) & 0x40) != 0) {
    uVar2 = uVar2 + (uint)*(ushort *)(&byte_tx_time + param_2 * 2) * -4;
  }
  uVar2 = uVar2 / *(ushort *)(&byte_tx_time + param_2 * 2);
  if (*(byte *)(iVar1 + 0x86) < uVar2) {
    uVar2 = (uint)*(byte *)(iVar1 + 0x86);
  }
  *(char *)(iVar1 + 0x8c) = (char)uVar2;
  r_ble_log_internal_x2(0x40a30083,param_2 << 0x18 | param_3 | param_1 << 0x10);
  return;
}

