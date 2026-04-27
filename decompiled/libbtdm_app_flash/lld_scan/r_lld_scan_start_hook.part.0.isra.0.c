/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_start_hook.part.0.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_start_hook_part_0_isra_0(int param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  
  piVar8 = _lld_scan_env;
  if ((param_1 == 0) && (_lld_scan_env != (int *)0x0)) {
    iVar9 = r_ble_ll_qa_config_get();
    piVar12 = piVar8 + 2;
    do {
      if (*piVar8 != 0) {
        bVar1 = *(byte *)(*piVar8 + 0x38);
        sVar2 = *(short *)(iVar9 + 0x14);
        iVar7 = (uint)bVar1 * 0x5a;
        if ((sVar2 != 0) && (*(short *)(iVar9 + 0x16) != 0)) {
          iVar10 = r_emi_get_mem_addr_by_offset(0x400);
          *(short *)(iVar10 + iVar7 + 0xc) = sVar2;
          uVar3 = *(undefined2 *)(iVar9 + 0x16);
          iVar10 = r_emi_get_mem_addr_by_offset(0x400);
          *(undefined2 *)(iVar10 + iVar7 + 0xe) = uVar3;
        }
        uVar4 = *(ushort *)(iVar9 + 0x18);
        iVar10 = iVar7 + 0x16;
        if (uVar4 != 0) {
          if ((uVar4 & 0xc0) != 0) {
            r_assert_err(0,"lld_scan.c",0x3cf);
          }
          iVar11 = r_emi_get_mem_addr_by_offset(0x400);
          uVar5 = *(ushort *)(iVar11 + iVar10);
          iVar11 = r_emi_get_mem_addr_by_offset(0x400);
          *(ushort *)(iVar11 + iVar10) = uVar4 & 0xff | uVar5 & 0xffc0;
        }
        iVar11 = r_emi_get_mem_addr_by_offset(0x400);
        uVar3 = *(undefined2 *)(iVar10 + iVar11);
        iVar10 = r_emi_get_mem_addr_by_offset(0x400);
        uVar6 = *(undefined2 *)(iVar10 + iVar7 + 0xc);
        iVar10 = r_emi_get_mem_addr_by_offset(0x400);
        r_ble_log_internal_x2
                  (0x40010139,CONCAT22(uVar6,uVar3),
                   (uint)CONCAT12(bVar1,*(undefined2 *)(iVar10 + iVar7 + 0xe)));
      }
      piVar8 = piVar8 + 1;
    } while (piVar12 != piVar8);
  }
  lld_rpa_renew_start(*(undefined1 *)(param_2 + 0x12));
  return;
}

