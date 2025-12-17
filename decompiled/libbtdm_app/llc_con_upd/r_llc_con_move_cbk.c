/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_con_move_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_con_move_cbk(uint param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  param_1 = param_1 & 0xff;
  iVar7 = param_1 * 4;
  if (*(int *)(&llc_env + iVar7) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x707,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (param_1 < *(byte *)(iVar2 + 0xd)) {
    iVar2 = *(int *)(&llc_env + iVar7);
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
      if (((*(byte *)(iVar2 + 0x45) & 0x10) == 0) && (-1 < (char)*(byte *)(iVar2 + 0x45))) {
        puVar3 = (undefined4 *)
                 (**(code **)(_r_modules_funcs_p + 200))
                           (0x10b,param_1 << 8 | 1,0x30,*(code **)(_r_modules_funcs_p + 200));
        iVar2 = (**(code **)(_r_ip_funcs_p + 0x4f0))(param_1,*(code **)(_r_ip_funcs_p + 0x4f0));
        if (*(int *)(&llc_env + iVar7) == 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x711,*(code **)(_r_plf_funcs_p + 8));
        }
        if (iVar2 == 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x712,*(code **)(_r_plf_funcs_p + 8));
        }
        if (*(int *)(iVar2 + 4) == 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"llc_con_upd.c",0x713,*(code **)(_r_plf_funcs_p + 8));
        }
        uVar8 = *(uint *)(iVar2 + 0xc);
        uVar6 = *(uint *)(iVar2 + 0x10);
        if ((*(ushort *)(*(int *)(&llc_env + iVar7) + 0x42) & 1) == 0) {
          if ((uVar8 < 4) || (uVar6 < uVar8)) {
            (**(code **)(_r_plf_funcs_p + 8))
                      (0,"llc_con_upd.c",0x71a,*(code **)(_r_plf_funcs_p + 8));
          }
          uVar8 = uVar8 - 3;
          uVar6 = uVar6 - 3;
        }
        *(undefined1 *)(puVar3 + 1) = 5;
        (**(code **)(_r_ip_funcs_p + 0x684))(puVar3,param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
        uVar5 = *(undefined4 *)(_r_ip_funcs_p + 0x5f8);
        *(short *)((int)puVar3 + 0x12) = (short)uVar6;
        *puVar3 = uVar5;
        iVar2 = *(int *)(&llc_env + iVar7);
        *(short *)(puVar3 + 4) = (short)uVar8;
        uVar1 = *(undefined2 *)(iVar2 + 0xe);
        *(undefined2 *)((int)puVar3 + 10) = uVar1;
        *(undefined2 *)(puVar3 + 2) = uVar1;
        *(undefined2 *)(puVar3 + 3) = *(undefined2 *)(iVar2 + 0x10);
        *(undefined2 *)((int)puVar3 + 0xe) = *(undefined2 *)(iVar2 + 0x12);
        bVar4 = 0;
        if ((*(ushort *)(iVar2 + 0x42) & 1) != 0) {
          iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
          bVar4 = 0;
          if ((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + iVar7), iVar2 != 0)
             ) {
            bVar4 = (byte)((int)(uint)*(byte *)(iVar2 + 0x30) >> 1) & 1;
          }
          bVar4 = bVar4 ^ 1;
        }
        *(byte *)(puVar3 + 0xb) = bVar4;
        *(undefined2 *)((int)puVar3 + 0x16) = 0xffff;
        iVar2 = _r_modules_funcs_p;
        *(undefined1 *)((int)puVar3 + 0x2d) = 0;
        *(undefined1 *)((int)puVar3 + 0x2e) = 0;
        (**(code **)(iVar2 + 0xe0))(puVar3,*(code **)(iVar2 + 0xe0));
        *(byte *)(*(int *)(&llc_env + iVar7) + 0x45) =
             *(byte *)(*(int *)(&llc_env + iVar7) + 0x45) | 0x80;
      }
    }
  }
  return;
}

