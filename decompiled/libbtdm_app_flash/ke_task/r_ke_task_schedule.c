/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ke_task.o -> r_ke_task_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_task_schedule(void)

{
  undefined4 *puVar1;
  int iVar2;
  code *pcVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  puVar1 = (undefined4 *)r_co_list_pop_front(&ke_env);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0xffffffff;
    iVar2 = r_ke_is_free(puVar1);
    if (iVar2 == 0) {
      pcVar3 = (code *)r_ke_task_handler_get_overwrite(puVar1);
      if (pcVar3 == (code *)0x0) {
        r_assert_warn(*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0xb4)
        ;
      }
      else {
        r_ke_task_handler_pre(puVar1);
        iVar2 = (*pcVar3)(*(undefined2 *)(puVar1 + 1),puVar1 + 3,*(undefined2 *)((int)puVar1 + 6),
                          *(undefined2 *)(puVar1 + 2));
        if (iVar2 == 1) goto _L46;
        if (iVar2 == 2) {
          r_co_list_push_back(&ke_env,puVar1);
          goto _L46;
        }
        if (iVar2 != 0) {
          r_assert_err(0,"ke_task.c",0xd7);
          goto _L46;
        }
      }
      r_ke_msg_free(puVar1);
    }
    else {
      r_assert_param(*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0xad);
    }
  }
_L46:
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (_ke_env == 0) {
    r_ke_event_clear(3);
  }
                    /* WARNING: Could not recover jumptable at 0x000102c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

