/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar3;
  ushort uVar4;
  int iVar5;
  
  uVar1 = (uint)DAT_00011100;
  iVar5 = uVar1 * 0x10;
  iVar2 = r_emi_get_mem_addr_by_offset(0);
  uVar4 = *(ushort *)(iVar2 + iVar5) >> 3 & 7;
  if (DAT_00011102 == '\0') {
    r_assert_err(0,"sch_prog.c",0xc6);
  }
  if (r_assert_param[iVar5] == (code)0x0) {
    r_assert_param(uVar4,uVar1,"sch_prog.c",0xc9);
  }
  if ((uVar4 - 3 & 0xff) < 3) {
    if (*(code **)(r_emi_get_mem_addr_by_offset + iVar5) == (code *)0x0) {
      r_assert_err(0,"sch_prog.c",0xe3);
    }
    else {
      (**(code **)(r_emi_get_mem_addr_by_offset + iVar5))
                (*(undefined4 *)(&sch_prog_env + iVar5),*(undefined4 *)(r_assert_err + iVar5),
                 uVar4 == 4);
    }
    uVar3 = (uint)DAT_00011101;
    DAT_00011102 = DAT_00011102 + -1;
    r_assert_param[iVar5] = (code)0x0;
    do {
      if (uVar3 == uVar1) break;
      uVar1 = uVar1 + 1 & 0xf;
    } while (r_assert_param[uVar1 * 0x10] == (code)0x0);
    DAT_00011100 = (byte)uVar1;
  }
  if (DAT_00011102 == '\0') {
    r_rwip_prevent_sleep_clear(0x200);
    return;
  }
  return;
}

