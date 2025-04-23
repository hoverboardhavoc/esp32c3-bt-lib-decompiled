/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_sch_prog_rx_isr(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = (uint)DAT_00011100;
  iVar3 = r_emi_get_mem_addr_by_offset(0);
  iVar2 = uVar1 * 0x10;
  if ((*(ushort *)(iVar3 + iVar2) >> 3 & 6) == 0) {
    r_assert_err(0,"sch_prog.c",0x17a);
  }
  if (DAT_00011102 == '\0') {
    r_assert_err(0,"sch_prog.c",0x17e);
  }
  if (r_assert_param[iVar2] == (code)0x0) {
    r_assert_err(0,"sch_prog.c",0x181);
  }
  if (*(code **)(r_emi_get_mem_addr_by_offset + iVar2) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001029e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(r_emi_get_mem_addr_by_offset + iVar2))
              (*(undefined4 *)(&sch_prog_env + iVar2),*(undefined4 *)(r_assert_err + iVar2),2);
    return;
  }
  return;
}

