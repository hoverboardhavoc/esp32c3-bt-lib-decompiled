/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x678))(1,*(code **)(_r_ip_funcs_p + 0x678));
  iVar6 = 0x24;
  if (iVar3 == 0) {
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x5e8))
                      (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                       *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8),
                       *(code **)(_r_ip_funcs_p + 0x5e8));
    iVar6 = 0x1e;
    if (iVar3 != 0) {
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x4e0))(5,*(code **)(_r_ip_funcs_p + 0x4e0));
      iVar6 = 0x1a;
      if (iVar3 != 0) {
        if (*(ushort *)(param_2 + 2) < 0xb) {
          uVar5 = (**(code **)(_r_ip_funcs_p + 0x7c8))(*(code **)(_r_ip_funcs_p + 0x7c8));
          if (1 < uVar5) {
            return 0x23;
          }
          if (*(char *)(iVar2 + 0x1c) == '\x03') {
            return 0x23;
          }
          if (*(char *)(iVar2 + 0x1d) == '\x03') {
            return 0x23;
          }
        }
        if (((*(ushort *)(iVar2 + 0x42) & 1) == 0) ||
           (iVar6 = (**(code **)(_r_ip_funcs_p + 0x66c))
                              (param_1,5,*(code **)(_r_ip_funcs_p + 0x66c)), iVar6 == 0)) {
          puVar4 = (undefined4 *)
                   (**(code **)(_r_modules_funcs_p + 200))
                             (0x10b,param_1 << 8 | 1,0x30,*(code **)(_r_modules_funcs_p + 200));
          *(undefined1 *)(puVar4 + 1) = 5;
          (**(code **)(_r_ip_funcs_p + 0x684))(param_1,7,*(code **)(_r_ip_funcs_p + 0x684));
          iVar2 = _r_ip_funcs_p;
          *puVar4 = *(undefined4 *)(_r_ip_funcs_p + 0x604);
          *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(param_2 + 2);
          *(undefined2 *)((int)puVar4 + 10) = *(undefined2 *)(param_2 + 4);
          *(undefined2 *)(puVar4 + 3) = *(undefined2 *)(param_2 + 6);
          *(undefined2 *)((int)puVar4 + 0xe) = *(undefined2 *)(param_2 + 8);
          *(undefined1 *)((int)puVar4 + 0x27) = *(undefined1 *)(param_2 + 10);
          pcVar7 = *(code **)(iVar2 + 0x67c);
          *(undefined2 *)(puVar4 + 5) = *(undefined2 *)(param_2 + 0xc);
          *(undefined2 *)((int)puVar4 + 0x16) = *(undefined2 *)(param_2 + 0xe);
          *(undefined2 *)(puVar4 + 6) = *(undefined2 *)(param_2 + 0x10);
          *(undefined2 *)((int)puVar4 + 0x1a) = *(undefined2 *)(param_2 + 0x12);
          *(undefined2 *)(puVar4 + 7) = *(undefined2 *)(param_2 + 0x14);
          *(undefined2 *)((int)puVar4 + 0x1e) = *(undefined2 *)(param_2 + 0x16);
          uVar1 = *(undefined2 *)(param_2 + 0x18);
          *(undefined1 *)((int)puVar4 + 0x2d) = 0;
          *(undefined1 *)((int)puVar4 + 0x2e) = 0;
          *(undefined2 *)(puVar4 + 8) = uVar1;
          (*pcVar7)(param_1,1,puVar4,pcVar7);
          (**(code **)(_r_ip_funcs_p + 0x600))(param_1,7,0,*(code **)(_r_ip_funcs_p + 0x600));
          iVar6 = 0;
        }
      }
    }
  }
  return iVar6;
}

