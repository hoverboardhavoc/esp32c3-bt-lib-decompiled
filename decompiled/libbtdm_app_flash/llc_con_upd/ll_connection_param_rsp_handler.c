/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> ll_connection_param_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ll_connection_param_rsp_handler(undefined4 param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  ushort uVar8;
  undefined4 uVar9;
  
  iVar5 = r_llc_proc_id_get(0);
  uVar9 = 0x24;
  if (iVar5 == 5) {
    iVar5 = r_llc_proc_get(param_1,0);
    uVar8 = *(ushort *)(param_2 + 4);
    uVar1 = *(ushort *)(param_2 + 2);
    sVar2 = *(short *)(param_2 + 6);
    uVar3 = *(ushort *)(param_2 + 8);
    iVar6 = r_llc_con_upd_param_in_range(param_1,uVar8,uVar1,sVar2,uVar3);
    uVar9 = 0x1e;
    if (iVar6 != 0) {
      uVar9 = 0x20;
      if (*(ushort *)(iVar5 + 8) <= uVar1) {
        uVar7 = *(ushort *)(iVar5 + 10);
        if ((((uVar1 <= uVar7) && (uVar8 <= uVar7)) && (*(ushort *)(iVar5 + 8) <= uVar8)) &&
           (*(short *)(iVar5 + 0xc) == sVar2)) {
          if (uVar7 < uVar8) {
            uVar7 = uVar8;
          }
          *(ushort *)(iVar5 + 8) = uVar7;
          uVar8 = *(ushort *)(iVar5 + 0xe);
          if (*(ushort *)(iVar5 + 0xe) < uVar3) {
            uVar8 = uVar3;
          }
          *(undefined1 *)(iVar5 + 0x26) = 0;
          *(ushort *)(iVar5 + 0xe) = uVar8;
          uVar4 = *(undefined2 *)(param_2 + 0xc);
          *(undefined2 *)(iVar5 + 0x22) = 0;
          uVar9 = 0;
          *(undefined2 *)(iVar5 + 0x14) = uVar4;
          *(undefined2 *)(iVar5 + 0x16) = *(undefined2 *)(param_2 + 0xe);
        }
      }
    }
    r_llc_loc_con_upd_proc_continue(param_1,2,uVar9);
  }
  return uVar9;
}

