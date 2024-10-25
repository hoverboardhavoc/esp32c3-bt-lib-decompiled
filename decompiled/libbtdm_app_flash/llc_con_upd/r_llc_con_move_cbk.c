/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_con_move_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_con_move_cbk(uint param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  param_1 = param_1 & 0xff;
  iVar5 = param_1 * 4;
  if (*(int *)(&llc_env + iVar5) == 0) {
    r_assert_err(0,"llc_con_upd.c",0x6ee);
  }
  iVar2 = r_sdk_config_get_opts();
  if (param_1 < *(byte *)(iVar2 + 0xd)) {
    iVar2 = *(int *)(&llc_env + iVar5);
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
      if (((*(byte *)(iVar2 + 0x45) & 0x10) == 0) && (-1 < (char)*(byte *)(iVar2 + 0x45))) {
        puVar3 = (undefined4 *)r_ke_msg_alloc(0x10b,param_1 << 8 | 1,0x30);
        iVar2 = r_llm_plan_elt_get(param_1);
        if (*(int *)(&llc_env + iVar5) == 0) {
          r_assert_err(0,"llc_con_upd.c",0x6f8);
        }
        if (iVar2 == 0) {
          r_assert_err(0,"llc_con_upd.c",0x6f9);
        }
        if (*(int *)(iVar2 + 4) == 0) {
          r_assert_err(0,"llc_con_upd.c",0x6fa);
        }
        uVar6 = *(uint *)(iVar2 + 0xc);
        uVar7 = *(uint *)(iVar2 + 0x10);
        if ((*(ushort *)(*(int *)(&llc_env + iVar5) + 0x42) & 1) == 0) {
          if ((uVar6 < 4) || (uVar7 < uVar6)) {
            r_assert_err(0,"llc_con_upd.c",0x701);
          }
          uVar6 = uVar6 - 3;
          uVar7 = uVar7 - 3;
        }
        *(undefined1 *)(puVar3 + 1) = 5;
        r_llc_proc_state_set(puVar3,param_1,0);
        *(short *)(puVar3 + 4) = (short)uVar6;
        *puVar3 = r_llc_loc_con_upd_proc_err_cb;
        iVar2 = *(int *)(&llc_env + iVar5);
        *(short *)((int)puVar3 + 0x12) = (short)uVar7;
        uVar1 = *(undefined2 *)(iVar2 + 0xe);
        *(undefined2 *)((int)puVar3 + 10) = uVar1;
        *(undefined2 *)(puVar3 + 2) = uVar1;
        *(undefined2 *)(puVar3 + 3) = *(undefined2 *)(iVar2 + 0x10);
        *(undefined2 *)((int)puVar3 + 0xe) = *(undefined2 *)(iVar2 + 0x12);
        bVar4 = 0;
        if ((*(ushort *)(iVar2 + 0x42) & 1) != 0) {
          iVar2 = r_sdk_config_get_opts();
          bVar4 = 0;
          if ((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + iVar5), iVar2 != 0)
             ) {
            bVar4 = (byte)((int)(uint)*(byte *)(iVar2 + 0x30) >> 1) & 1;
          }
          bVar4 = bVar4 ^ 1;
        }
        *(byte *)(puVar3 + 0xb) = bVar4;
        *(undefined2 *)((int)puVar3 + 0x16) = 0xffff;
        *(undefined1 *)((int)puVar3 + 0x2d) = 0;
        *(undefined1 *)((int)puVar3 + 0x2e) = 0;
        r_ke_msg_send(puVar3);
        *(byte *)(*(int *)(&llc_env + iVar5) + 0x45) =
             *(byte *)(*(int *)(&llc_env + iVar5) + 0x45) | 0x80;
      }
    }
  }
  return;
}

