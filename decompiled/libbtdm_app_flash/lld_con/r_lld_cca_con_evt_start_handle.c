/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_cca_con_evt_start_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_con_evt_start_handle(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  undefined1 uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  
  puVar7 = (undefined4 *)r_lld_cca_get_cca_env();
  bVar1 = *(byte *)(param_1 + 0x8e);
  iVar5 = (uint)bVar1 * 0x5a;
  uVar8 = r_lld_read_clock();
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  uVar2 = *(undefined2 *)(iVar5 + 0x50 + iVar9);
  *(byte *)((int)puVar7 + 0xd) = bVar1;
  puVar11 = puVar7 + 8;
  *(short *)((int)puVar7 + 0xe) = (short)(*(uint *)(param_1 + 100) >> 1);
  *(short *)(puVar7 + 5) =
       (short)(((*(ushort *)(&max_data_tx_time + (uint)*(byte *)(param_1 + 0x94) * 2) + 0x96 +
                (uint)*(ushort *)(&fixed_tx_time + (uint)*(byte *)(param_1 + 0x93) * 2)) * 2) /
               0x271 + 1 >> 1);
  *(undefined1 *)((int)puVar7 + 0x26) = *(undefined1 *)(param_1 + 0x46);
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  uVar3 = *(undefined2 *)(iVar5 + 0x22 + iVar9);
  *(char *)(puVar7 + 8) = (char)uVar3;
  *(char *)((int)puVar7 + 0x21) = (char)((ushort)uVar3 >> 8);
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  uVar3 = *(undefined2 *)(iVar5 + 0x24 + iVar9);
  *(char *)((int)puVar7 + 0x22) = (char)uVar3;
  *(char *)((int)puVar7 + 0x23) = (char)((ushort)uVar3 >> 8);
  iVar9 = r_emi_get_mem_addr_by_offset(0x400);
  *(char *)(puVar7 + 9) = (char)*(undefined2 *)(iVar5 + 0x26 + iVar9);
  uVar10 = r_co_nb_good_le_channels(puVar11);
  *(char *)((int)puVar7 + 0x25) = (char)uVar10;
  if ((*(ushort *)(param_1 + 0x84) & 0x200) == 0) {
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(ushort *)(iVar5 + 0xe + iVar9);
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    uVar6 = r_lld_cca_chan_sel_2
                      (uVar2,*(ushort *)(iVar5 + 0xc + iVar9) ^ uVar4,puVar11,
                       *(undefined1 *)((int)puVar7 + 0x25));
  }
  else {
    uVar6 = r_lld_cca_chan_sel_1
                      (*(undefined1 *)(param_1 + 0x80),*(undefined1 *)(param_1 + 0x8d),
                       *(undefined2 *)(param_1 + 0x72),puVar11,uVar10);
  }
  *(undefined1 *)(puVar7 + 2) = uVar6;
  if ((code *)*puVar7 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010238. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*puVar7)(uVar8,0);
    return;
  }
  return;
}

