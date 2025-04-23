/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_end_isr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_sch_prog_end_isr_handler(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  
  uVar1 = (uint)DAT_00011100;
  iVar2 = r_emi_get_mem_addr_by_offset(0);
  iVar3 = uVar1 * 0x10;
  uVar4 = *(ushort *)(iVar2 + iVar3) >> 3 & 7;
  if (DAT_00011102 == '\0') {
    r_assert_err(0,"sch_prog.c",0xc6);
  }
  if (r_assert_param[iVar3] == (code)0x0) {
    r_assert_param(uVar4,uVar1,"sch_prog.c",0xc9);
  }
  if ((uVar4 - 3 & 0xff) < 3) {
    if (*(code **)(r_emi_get_mem_addr_by_offset + iVar3) == (code *)0x0) {
      r_assert_err(0,"sch_prog.c",0xe3);
    }
    else {
      (**(code **)(r_emi_get_mem_addr_by_offset + iVar3))
                (*(undefined4 *)(&sch_prog_env + iVar3),*(undefined4 *)(r_assert_err + iVar3),
                 uVar4 == 4);
    }
    r_assert_param[iVar3] = (code)0x0;
    DAT_00011102 = DAT_00011102 + -1;
    for (; (r_assert_param[uVar1 * 0x10] == (code)0x0 && (DAT_00011101 != uVar1));
        uVar1 = uVar1 + 1 & 0xf) {
    }
    DAT_00011100 = (byte)uVar1;
  }
  if (DAT_00011102 == '\0') {
    r_rwip_prevent_sleep_clear(0x200);
    return;
  }
  return;
}

