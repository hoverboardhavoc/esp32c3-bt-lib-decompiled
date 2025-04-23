/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_start_hook.part.0.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_start_hook_part_0_isra_0(int param_1,int param_2)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  piVar6 = _lld_scan_env;
  if ((param_1 == 0) && (_lld_scan_env != (int *)0x0)) {
    iVar7 = r_ble_ll_qa_config_get();
    piVar10 = piVar6 + 2;
    do {
      if (*piVar6 != 0) {
        sVar1 = *(short *)(iVar7 + 0x14);
        uVar5 = (uint)*(byte *)(*piVar6 + 0x38);
        if ((sVar1 != 0) && (*(short *)(iVar7 + 0x16) != 0)) {
          iVar9 = uVar5 * 0x5a;
          iVar8 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar9 + 0xc + iVar8) = sVar1;
          uVar2 = *(undefined2 *)(iVar7 + 0x16);
          iVar8 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar9 + 0xe + iVar8) = uVar2;
        }
        uVar3 = *(ushort *)(iVar7 + 0x18);
        if (uVar3 != 0) {
          if (0x3f < (uVar3 & 0xff)) {
            r_assert_err(0,"lld_scan.c",0x3cf);
          }
          iVar9 = r_emi_get_mem_addr_by_offset(0x400);
          iVar8 = uVar5 * 0x5a + 0x16;
          uVar4 = *(ushort *)(iVar9 + iVar8);
          iVar9 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar8 + iVar9) = uVar4 & 0xffc0 | uVar3 & 0xff;
        }
      }
      piVar6 = piVar6 + 1;
    } while (piVar6 != piVar10);
  }
  lld_rpa_renew_start(*(undefined1 *)(param_2 + 0x12));
  return;
}

