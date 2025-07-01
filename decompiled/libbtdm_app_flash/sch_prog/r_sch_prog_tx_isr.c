/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_tx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_sch_prog_tx_isr(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = (uint)DAT_00011100;
  iVar3 = r_emi_get_mem_addr_by_offset(0);
  iVar2 = uVar1 * 0x10;
  if ((*(ushort *)(iVar3 + iVar2) >> 3 & 6) == 0) {
    r_assert_err(0,"sch_prog.c",0x19b);
  }
  if (DAT_00011102 == '\0') {
    r_assert_err(0,"sch_prog.c",0x19f);
  }
  if (r_assert_param[iVar2] == (code)0x0) {
    r_assert_err(0,"sch_prog.c",0x1a2);
  }
  if (*(code **)(r_emi_get_mem_addr_by_offset + iVar2) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010346. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(r_emi_get_mem_addr_by_offset + iVar2))
              (*(undefined4 *)(&sch_prog_env + iVar2),*(undefined4 *)(r_assert_err + iVar2),3);
    return;
  }
  return;
}

