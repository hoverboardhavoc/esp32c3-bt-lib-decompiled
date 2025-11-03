/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_adv.o -> r_llm_per_adv_slot_dur
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint r_llm_per_adv_slot_dur(uint param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0x672 < param_1) {
    r_assert_err(0,"llm_adv.c",0xccd);
  }
  iVar1 = (param_1 / 0xf0 + 1 & 0xff) - 1;
  iVar2 = r_co_ble_pkt_dur_in_us(0xff);
  iVar3 = r_co_ble_pkt_dur_in_us((param_1 + iVar1 * -0xf0 & 0xffff) + 1 & 0xff,param_2 + -1);
  return (uint)(iVar3 + 300 + (iVar2 + 300) * iVar1) / 0x271 + 1 & 0xff;
}

