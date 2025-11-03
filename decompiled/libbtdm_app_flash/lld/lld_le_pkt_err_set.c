/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld.o -> lld_le_pkt_err_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void lld_le_pkt_err_set(uint param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  
  if (0xb < param_1) {
    r_assert_param(0xc,"lld.c",0x2cd);
  }
  iVar2 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar1 = *(ushort *)(param_2 * 0x14 + 2 + iVar2);
  if ((uVar1 & 0xf) != 0) {
    if ((uVar1 & 1) != 0) {
      *(short *)(&lld_le_pkt_env + param_1) = *(short *)(&lld_le_pkt_env + param_1) + 1;
    }
    if ((uVar1 & 8) != 0) {
      *(short *)((int)&lld_le_pkt_env + param_1 * 4 + 2) =
           *(short *)((int)&lld_le_pkt_env + param_1 * 4 + 2) + 1;
    }
  }
  return;
}

