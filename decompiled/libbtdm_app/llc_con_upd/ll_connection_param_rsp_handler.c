/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> ll_connection_param_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_connection_param_rsp_handler(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  undefined4 uVar5;
  
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(0,*(code **)(_r_ip_funcs_p + 0x678));
  uVar5 = 0x24;
  if (iVar2 == 5) {
    uVar5 = 0x1e;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,0,*(code **)(_r_ip_funcs_p + 0x674));
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x5e8))
                      (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                       *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8),
                       *(code **)(_r_ip_funcs_p + 0x5e8));
    if (iVar3 != 0) {
      uVar5 = 0x20;
      if (*(ushort *)(iVar2 + 8) <= *(ushort *)(param_2 + 2)) {
        uVar4 = *(ushort *)(iVar2 + 10);
        if ((((*(ushort *)(param_2 + 2) <= uVar4) && (*(ushort *)(param_2 + 4) <= uVar4)) &&
            (*(ushort *)(iVar2 + 8) <= *(ushort *)(param_2 + 4))) &&
           (*(short *)(param_2 + 6) == *(short *)(iVar2 + 0xc))) {
          *(ushort *)(iVar2 + 8) = uVar4;
          uVar4 = *(ushort *)(iVar2 + 0xe);
          if (*(ushort *)(iVar2 + 0xe) < *(ushort *)(param_2 + 8)) {
            uVar4 = *(ushort *)(param_2 + 8);
          }
          *(undefined1 *)(iVar2 + 0x26) = 0;
          *(ushort *)(iVar2 + 0xe) = uVar4;
          uVar1 = *(undefined2 *)(param_2 + 0xc);
          *(undefined2 *)(iVar2 + 0x22) = 0;
          uVar5 = 0;
          *(undefined2 *)(iVar2 + 0x14) = uVar1;
          *(undefined2 *)(iVar2 + 0x16) = *(undefined2 *)(param_2 + 0xe);
        }
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x5f4))(param_1,2,uVar5,*(code **)(_r_ip_funcs_p + 0x5f4));
  }
  return uVar5;
}

