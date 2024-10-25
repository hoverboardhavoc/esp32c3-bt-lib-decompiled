/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> ll_connection_param_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ll_connection_param_req_handler(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  
  iVar7 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(1,*(code **)(_r_ip_funcs_p + 0x678));
  iVar5 = 0x24;
  if (iVar2 == 0) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x5e8))
                      (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                       *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8),
                       *(code **)(_r_ip_funcs_p + 0x5e8));
    iVar5 = 0x1e;
    if (iVar2 != 0) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x4e0))(5,*(code **)(_r_ip_funcs_p + 0x4e0));
      iVar5 = 0x1a;
      if (iVar2 != 0) {
        if (*(ushort *)(param_2 + 2) < 0xb) {
          uVar4 = (**(code **)(_r_ip_funcs_p + 0x7c8))(*(code **)(_r_ip_funcs_p + 0x7c8));
          if (1 < uVar4) {
            return 0x23;
          }
          if (*(char *)(iVar7 + 0x1c) == '\x03') {
            return 0x23;
          }
          if (*(char *)(iVar7 + 0x1d) == '\x03') {
            return 0x23;
          }
        }
        if (((*(ushort *)(iVar7 + 0x42) & 1) == 0) ||
           (iVar5 = (**(code **)(_r_ip_funcs_p + 0x66c))
                              (param_1,5,*(code **)(_r_ip_funcs_p + 0x66c)), iVar5 == 0)) {
          puVar3 = (undefined4 *)
                   (**(code **)(_r_modules_funcs_p + 200))
                             (0x10b,param_1 << 8 | 1,0x30,*(code **)(_r_modules_funcs_p + 200));
          *(undefined1 *)(puVar3 + 1) = 5;
          (**(code **)(_r_ip_funcs_p + 0x684))(param_1,7,*(code **)(_r_ip_funcs_p + 0x684));
          iVar2 = _r_ip_funcs_p;
          *puVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x604);
          *(undefined2 *)(puVar3 + 2) = *(undefined2 *)(param_2 + 2);
          *(undefined2 *)((int)puVar3 + 10) = *(undefined2 *)(param_2 + 4);
          *(undefined2 *)(puVar3 + 3) = *(undefined2 *)(param_2 + 6);
          *(undefined2 *)((int)puVar3 + 0xe) = *(undefined2 *)(param_2 + 8);
          *(undefined1 *)((int)puVar3 + 0x27) = *(undefined1 *)(param_2 + 10);
          pcVar6 = *(code **)(iVar2 + 0x67c);
          *(undefined2 *)(puVar3 + 5) = *(undefined2 *)(param_2 + 0xc);
          *(undefined2 *)((int)puVar3 + 0x16) = *(undefined2 *)(param_2 + 0xe);
          *(undefined2 *)(puVar3 + 6) = *(undefined2 *)(param_2 + 0x10);
          *(undefined2 *)((int)puVar3 + 0x1a) = *(undefined2 *)(param_2 + 0x12);
          *(undefined2 *)(puVar3 + 7) = *(undefined2 *)(param_2 + 0x14);
          *(undefined2 *)((int)puVar3 + 0x1e) = *(undefined2 *)(param_2 + 0x16);
          uVar1 = *(undefined2 *)(param_2 + 0x18);
          *(undefined1 *)((int)puVar3 + 0x2d) = 0;
          *(undefined1 *)((int)puVar3 + 0x2e) = 0;
          *(undefined2 *)(puVar3 + 8) = uVar1;
          (*pcVar6)(param_1,1,puVar3,pcVar6);
          (**(code **)(_r_ip_funcs_p + 0x600))(param_1,7,0,*(code **)(_r_ip_funcs_p + 0x600));
          iVar5 = 0;
        }
      }
    }
  }
  return iVar5;
}

