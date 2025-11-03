/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_sch_prog_skip_isr(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_00011102 == '\0') {
    r_assert_err(0,"sch_prog.c",0x1fa);
  }
  uVar1 = (uint)DAT_00011100;
  while( true ) {
    if (DAT_00011102 == '\0') {
      r_rwip_prevent_sleep_clear_hack(0x200);
      return;
    }
    if (DAT_00011101 == uVar1) break;
    iVar3 = uVar1 * 0x10;
    if ((r_assert_param[iVar3] != (code)0x0) &&
       (iVar2 = r_emi_get_mem_addr_by_offset(0), (*(ushort *)(iVar2 + iVar3) >> 3 & 7) == 6)) {
      if (*(code **)(r_emi_get_mem_addr_by_offset + iVar3) == (code *)0x0) {
        r_assert_err(0,"sch_prog.c",0x20f);
      }
      else {
        (**(code **)(r_emi_get_mem_addr_by_offset + iVar3))
                  (*(undefined4 *)(&sch_prog_env + iVar3),*(undefined4 *)(r_assert_err + iVar3),4);
      }
      if (DAT_00011100 == uVar1) {
        DAT_00011100 = (byte)(uVar1 + 1) & 0xf;
      }
      r_assert_param[iVar3] = (code)0x0;
      DAT_00011102 = DAT_00011102 + -1;
    }
    uVar1 = uVar1 + 1 & 0xf;
  }
  if (DAT_00011102 == '\x01') {
    DAT_00011101 = DAT_00011100 + 1 & 0xf;
  }
  return;
}

